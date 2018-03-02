%%
clear all;
close all;
clc;

%% Set Up Webcam
cam = webcam('HP USB Webcam');
preview(cam);

command = input('Take Background Picture? [Y/N]: ', 's');
if (strcmp('Y', command) == 1)
    background = snapshot(cam);
    figure, imshow(background);
end

%% Get SnapShot
command2 = input('Take Snapshot Picture? [Y/N]: ', 's');
if (strcmp('Y', command2) == 1)
    snapShot = snapshot(cam);
    figure, imshow(snapShot);
end
%% Get Images and Turn it to Gray Scale

d = impixel(snapShot);
backgroundG = rgb2gray(background);
snapShotG = rgb2gray(snapShot);

%% Take difference between Backgroun and Snapshot
difference = backgroundG - snapShotG;
figure, imshow(difference);

%% Obtain Gray Scale of Difference
diffI = im2bw(difference, 0.55);

%% Erosion and Dilution
se = strel('disk', 1);
erode = imerode(diffI,se);
figure, imshow(erode);
se2 = strel('disk', 2);
dilute = imdilate(erode, se2);
figure, imshow(dilute);
se3 = strel('disk', 3);
dilute2 = imdilate(dilute, se3);
figure, imshow(dilute2);
se4 = strel('disk', 4);
dilute3 = imdilate(dilute2, se4);
figure, imshow(dilute3);
se5 = strel('disk', 5);
dilute4 = imdilate(dilute3, se5);
figure, imshow(dilute4);

%% Fill Image
image = imfill(dilute2, 'holes');
figure, imshow(image);

%% Get Picture information

%connectedComponents = bwconncomp(image);

properties = regionprops(image);

figure, imshow(snapShot);

hold on;
for c1 = 1: numel(properties.Area)
    plot(floor(properties(1).Centroid(1)), floor(properties(1).Centroid(2)),'rx');
end
hold off;

if (snapShot(floor(properties(1).Centroid(1)), floor(properties(1).Centroid(2)), 1) > 180)
    fprintf("RED\n");
else
    fprintf('Not RED\n');
end


%redLayer = image(:, :, 1);
%blueLayer = image(:, :, 2);
%greenLayer = image(:, :, 3);
%figure, imshow(redLayer);
%figure, imshow(blueLayer);
%figure, imshow(greenLayer);
%d = impixel(image);
%%
%outputRed = redLayer > 165 & greenLayer > 38 & greenLayer < 100 & blueLayer < 120;
%outputGreen = redLayer > 58 & redLayer < 88 & greenLayer > 89 & greenLayer < 130 & blueLayer > 74 & blueLayer < 118;
%figure, imshow(outputRed);