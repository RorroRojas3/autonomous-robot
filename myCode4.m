%%
clear all;
close all;
clc;
imaqreset;

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

%% Get Background Image
background = getBackgroundImage(cam);

%% Get SnapShot Image

snapShot = getSnapshotImage(cam);

%% Get Images and Turn it to Gray Scale

%background = imread('gameboard.png');
%snapShot = imread('colors.png');
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
centroidNumber(snapShot, properties);

%% Labels where program is getting RGB value for each washer
rgbPoints(snapShot, properties);

%% Determines number of RED Washers
redWasher = getRedWasher(snapShot, properties);
fprintf('\n');

%%  Determine the angle of Washers based on Pixels 
degrees = getWashersDegrees(properties);

%% Target PC Set Up
tg = setTargetPC();

%% Degree Test
rotateMotor(degrees, redWasher, tg);

tg.stop;




