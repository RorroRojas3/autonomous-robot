%%
clear all;
close all;
clc;
imaqreset;

%% Set Up Webcam
%gameState.cam = webcam('HP USB Webcam');
%preview(gameState.cam);

%% Align Board with Camera
% while (1)
%     back = snapshot(gameState.cam);
%     imshow(back);
%     hold on;
%     plot(320, 240, 'rx');
%     hold off;
% end

%% Get Background Image
gameState.background = imread('back1.jpg'); %getBackgroundImage(gameState.cam);
figure, imshow(gameState.background);
%% Get SnapShot Image
gameState.snapShot = imread('back2.jpg');%getSnapshotImage(gameState.cam);
figure, imshow(gameState.snapShot);
%% Get Images and Turn it to Gray Scale

% background = imread('gameboard.png');a
% snapShot = imread('colors.png');
gameState.backgroundG = rgb2gray(gameState.background);
gameState.snapShotG = rgb2gray(gameState.snapShot);

%% Take difference between Backgroun and Snapshot
gameState.difference = gameState.backgroundG - gameState.snapShotG;
figure, imshow(gameState.difference);

%% Obtain Gray Scale of Difference
gameState.diffI = im2bw(gameState.difference, 0.15);
%figure, imshow(gameState.diffI);

%% Erosion and Dilution
se = strel('disk', 3);
gameState.erode = imerode(gameState.diffI,se);
figure, imshow(gameState.erode);
se2 = strel('disk', 10);
gameState.dilute = imdilate(gameState.erode, se2);
figure, imshow(gameState.dilute);

%% Fill Image
gameState.fillImage = imfill(gameState.dilute, 'holes');
figure, imshow(gameState.fillImage);

%% Get Area and Centroid Information
gameState.props = regionprops(gameState.fillImage);

%% Labels each Washer by their number
centroidNumber(gameState.snapShot, gameState.props);

%% Labels where program is getting RGB value for each washer
rgbPoints(gameState.snapShot, gameState.props);

%% Determines number of RED Washers
fprintf('\n\n');
gameState.allWashers = getAllWashers(gameState.snapShot, gameState.props);

% if (gameState.allWashers(1) == 0)
%     clear all;
%     close all;
%     clc;
%     imaqreset;
%     fprintf('No Red Washers detected\n');
%     fprintf('Program will be terminated\n');
% else
    %%  Determine the angle of Washers based on Pixels 
    gameState.degrees = getWashersDegrees(gameState.props);
    
    cell = sortColorAndDegrees(gameState.wellLocations, gameState.allWashers, gameState.degrees);
    
%     %% Target PC Set Up
%     tg = setTargetPC();
% 
%     %% Degree Test
%     rotateMotorDemo(gameState.degrees, gameState.redWasher, tg);
% 
%     %% Stop Simulink
%     tg.stop;
% end




