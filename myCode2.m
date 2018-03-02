%% Configure camera and capture image from Video Input
video = videoinput('winvideo', 1);
start(video);
preview(video);

%% Acquire Image from Video

% Closes the video preview
closepreview(video);
% Takes a picture of the video
snapShot = getsnapshot(video);
% Stops de video
stop(video);
% Deletes the video
delete(video);
% Display image taken from video
figure, imshow(snapShot);

%% Thresholding the Image on Each color Plane
image = im2double(snapShot);
[r c p] = size(image);

% Extract individuals plane from RGB Image
red = squeeze(image(:,:,1));
green = squeeze(image(:,:,2));
blue = squeeze(image(:,:,3));

%Trhesholding on Individual Planes

redBinary = im2bw(red, graythresh(red));
greenBinary = im2bw(green, graythresh(green));
blueBinary = im2bw(blue, graythresh(blue));
binaryImage = imcomplement(redBinary&greenBinary&blueBinary);
figure, imshow(binaryImage);

%% Morphological Opening

se = strel('disk', 7);
clean = imopen(binaryImage, se);

%% Fill holes and Clear Border

clean = imfill(clean, 'holes');
clean = imclearborder(clean);
figure, imshow(clean);

%% Segmented gray-level image
[labels, numberOfLabels] = bwlabel(clean);
disp(['Number of Objects detected: ' num2str(numberOfLabels)]);

%% Initialize Matrices

redLabel = zeros(r, c);
greenLabel = zeros(r, c);
blueLabel = zeros(r, c);

%% Get the average color vector for each labeled region
for i=1:numberOfLabels
    redLabel(labels == i) = median(red(labels==i));
    greenLabel(labels == i) = median(green(labels == i));
    blueLabel(labels == i) = median(blue(labels == i));
end

imageLabel = cat(3, redLabel, greenLabel, blueLabel);
figure, imshow(imageLabel);
impixelinfo(gcf);

%% Get the desired Color
[x, y] = ginput(1);
selectColor = imageLabel(floor(y), floor(x), :);

%% Convert to LAB color space
C = makecform('srgb2lab');
imageLab = applycform(imageLabel, C);
imageSelLab = applycform(selectColor, C);

%% Exract a* and b* values
imageA = imageLab(:, :, 2);
imageB = imageLab(:, :, 3);
imageSelA = imageSelLab(1, 2);
imageSelB = imageSelLab(1, 3);

%% Compute distance from selected color
distanceTreshold = 10;
imageMask = zeros(r, c);
imageDistance = hypot(imageA-imageSelA, imageB-imageSelB);
imageMask(imageDistance < distanceTreshold) = 1;
[cLabel, cNum] = bwlabel(imageMask);
imageSegment = repmat(selectColor, [r, c, 1]).*repmat(imageMask, [1,1,3]);
figure, imshow(imageSegment);


