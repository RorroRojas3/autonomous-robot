%%
clear all;
close all;
clc;

%% Set Up Webcam
cam = webcam('HP USB Webcam');
preview(cam);

% while (1)
%     back = snapshot(cam);
%     imshow(back);
%     hold on;
%     plot(320, 240, 'rx');
%     hold off;
% end

command = input('Take Background Picture? [Y/N]: ', 's');
if (strcmp('Y', command) == 1)
    background = snapshot(cam);
    %figure, imshow(background);
end

%% Get SnapShot
command2 = input('Take Snapshot Picture? [Y/N]: ', 's');
if (strcmp('Y', command2) == 1)
    snapShot = snapshot(cam);
    %figure, imshow(snapShot);
end
%% Get Images and Turn it to Gray Scale

% background = imread('gameboard.png');
% snapShot = imread('colors.png');
backgroundG = rgb2gray(background);
snapShotG = rgb2gray(snapShot);

%% Take difference between Backgroun and Snapshot
difference = backgroundG - snapShotG;
figure, imshow(difference);

%% Obtain Gray Scale of Difference
diffI = im2bw(difference, 0.15);
%imshow(diffI);

%% Erosion and Dilution
se = strel('disk', 3);
erode = imerode(diffI,se);
%figure, imshow(erode);
se2 = strel('disk', 10);
dilute = imdilate(erode, se2);
%figure, imshow(dilute);

%% Fill Image
image = imfill(dilute, 'holes');
figure, imshow(image);

%% Get Area and Centroid Information

properties = regionprops(image);

%% Labels each Washer by their number
figure, imshow(snapShot);
hold on;
for c1 = 1: numel(properties)
    text(properties(c1).Centroid(1), properties(c1).Centroid(2), sprintf('%d', c1), ...
    'HorizontalAlignment', 'center', ...
    'VerticalAlignment', 'middle');
end
hold off;

%% Labels where program is getting RGB value for each washer
figure, imshow(snapShot);
hold on;
for c1 = 1:numel(properties)
   radius = sqrt(properties(c1).Area / pi);
   halfRadius = radius / 2;
   plot(floor(properties(c1).Centroid(1) - halfRadius), floor(properties(c1).Centroid(2)), 'rx'); 
end
plot(640/2, 480/2, 'rx');
hold off;

%%  Determines the color of each washer
for c1 = 1:numel(properties)
    radius = sqrt(properties(c1).Area / pi);
    halfRadius = radius / 2;
    redColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 1);
    greenColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 2);
    blueColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 3);
    fprintf('Washer #%d | R(%d), G(%d), B(%d) | ', c1, redColor, greenColor, blueColor);
    if (redColor > 118)
        fprintf("RED\n", c1);
    else
        fprintf('Not RED\n');
    end
end
fprintf('\n');

%%  Determine the angle of Washers based on Pixels 
for c1= 1:numel(properties)
    x(c1) =  (640 / 2) - properties(c1).Centroid(1);
    y(c1) = (480 / 2) - properties(c1).Centroid(2);
    degrees(c1) = atand(y / x);
    fprintf('Washer #%d | X: %.3f | Y: %.3f | Degree: %.3f\n', c1, x(c1), y(c1), degrees(c1));
end

