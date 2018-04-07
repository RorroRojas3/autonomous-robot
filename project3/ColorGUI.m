function varargout = ColorGUI(varargin)
% COLORGUI MATLAB code for ColorGUI.fig
%      COLORGUI, by itself, creates a new COLORGUI or raises the existing
%      singleton*.
%
%      H = COLORGUI returns the handle to a new COLORGUI or the handle to
%      the existing singleton*.
%
%      COLORGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in COLORGUI.M with the given input arguments.
%
%      COLORGUI('Property','Value',...) creates a new COLORGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ColorGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ColorGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ColorGUI

% Last Modified by GUIDE v2.5 06-Mar-2018 20:02:52

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ColorGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @ColorGUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ColorGUI is made visible.
function ColorGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ColorGUI (see VARARGIN)

% Choose default command line output for ColorGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ColorGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ColorGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in redColors.
function redColors_Callback(hObject, eventdata, handles)
%%
clear all;
close all;
clc;
imaqreset;
fprintf('User chose Red Washers\n');
%% Set Up Webcam
gameState.cam = webcam('HP USB Webcam');
preview(gameState.cam);

%% Align Board with Camera
% while (1)
%     back = snapshot(cam);
%     imshow(back);
%     hold on;
%     plot(320, 240, 'rx');
%     hold off;
% end

%% Get Background Image
gameState.background = getBackgroundImage(gameState.cam);

%% Get SnapShot Image

gameState.snapShot = getSnapshotImage(gameState.cam);

%% Get Images and Turn it to Gray Scale

gameState.backgroundG = rgb2gray(gameState.background);
gameState.snapShotG = rgb2gray(gameState.snapShot);

%% Take difference between Backgroun and Snapshot
gameState.difference = gameState.backgroundG - gameState.snapShotG;
figure, imshow(gameState.difference);

%% Obtain Gray Scale of Difference
gameState.diffI = im2bw(gameState.difference, 0.15);
%imshow(diffI);

%% Erosion and Dilution
se = strel('disk', 3);
gameState.erode = imerode(gameState.diffI,se);
%figure, imshow(erode);
se2 = strel('disk', 10);
gameState.dilute = imdilate(gameState.erode, se2);
%figure, imshow(dilute);

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
gameState.redWasher = getRedWasher(gameState.snapShot, gameState.props);

if (gameState.redWasher(1) == 0)
    clear all;
    close all;
    clc;
    imaqreset;
    fprintf('No Red Washers detected\n');
    fprintf('Program will be terminated\n');
else
    %%  Determine the angle of Washers based on Pixels 
    gameState.degrees = getWashersDegrees(gameState.props);

    %% Target PC Set Up
    tg = setTargetPC();

    %% Degree Test
    rotateMotor(gameState.degrees, gameState.redWasher, tg);

    %% Stop Simulink
    tg.stop;
end

% --- Executes on button press in greenColors.
function greenColors_Callback(hObject, eventdata, handles)
%%
clear all;
close all;
clc;
imaqreset;
fprintf('User chose Green Washers\n');
%% Set Up Webcam
gameState.cam = webcam('HP USB Webcam');
preview(gameState.cam);

%% Align Board with Camera
% while (1)
%     back = snapshot(cam);
%     imshow(back);
%     hold on;
%     plot(320, 240, 'rx');
%     hold off;
% end

%% Get Background Image
gameState.background = getBackgroundImage(gameState.cam);

%% Get SnapShot Image

gameState.snapShot = getSnapshotImage(gameState.cam);

%% Get Images and Turn it to Gray Scale

gameState.backgroundG = rgb2gray(gameState.background);
gameState.snapShotG = rgb2gray(gameState.snapShot);

%% Take difference between Backgroun and Snapshot
gameState.difference = gameState.backgroundG - gameState.snapShotG;
figure, imshow(gameState.difference);

%% Obtain Gray Scale of Difference
gameState.diffI = im2bw(gameState.difference, 0.15);
%imshow(diffI);

%% Erosion and Dilution
se = strel('disk', 3);
gameState.erode = imerode(gameState.diffI,se);
%figure, imshow(erode);
se2 = strel('disk', 10);
gameState.dilute = imdilate(gameState.erode, se2);
%figure, imshow(dilute);

%% Fill Image
gameState.fillImage = imfill(gameState.dilute, 'holes');
figure, imshow(gameState.fillImage);

%% Get Area and Centroid Information
gameState.props = regionprops(gameState.fillImage);

%% Labels each Washer by their number
centroidNumber(gameState.snapShot, gameState.props);

%% Labels where program is getting RGB value for each washer
rgbPoints(gameState.snapShot, gameState.props);

%% Determines number of GREEN Washers
gameState.greenWasher = getGreenWasher(gameState.snapShot, gameState.props);

if (gameState.greenWasher(1) == 0)
    clear all;
    close all;
    clc;
    imaqreset;
    fprintf('No Green Washers detected\n');
    fprintf('Program will be terminated\n');
else
    %%  Determine the angle of Washers based on Pixels 
    gameState.degrees = getWashersDegrees(gameState.props);

    %% Target PC Set Up
    tg = setTargetPC();

    %% Degree Test
    rotateMotor(gameState.degrees, gameState.greenWasher, tg);

    %% Stop Simulink
    tg.stop;
end

% --- Executes on button press in blueColors.
function blueColors_Callback(hObject, eventdata, handles)
%%
clear all;
close all;
clc;
imaqreset;
fprintf('User chose Blue Washers\n');
%% Set Up Webcam
gameState.cam = webcam('HP USB Webcam');
preview(gameState.cam);

%% Align Board with Camera
% while (1)
%     back = snapshot(cam);
%     imshow(back);
%     hold on;
%     plot(320, 240, 'rx');
%     hold off;
% end

%% Get Background Image
gameState.background = getBackgroundImage(gameState.cam);

%% Get SnapShot Image
gameState.snapShot = getSnapshotImage(gameState.cam);

%% Get Images and Turn it to Gray Scale
gameState.backgroundG = rgb2gray(gameState.background);
gameState.snapShotG = rgb2gray(gameState.snapShot);

%% Take difference between Backgroun and Snapshot
gameState.difference = gameState.backgroundG - gameState.snapShotG;
figure, imshow(gameState.difference);

%% Obtain Gray Scale of Difference
gameState.diffI = im2bw(gameState.difference, 0.15);
%imshow(diffI);

%% Erosion and Dilution
se = strel('disk', 3);
gameState.erode = imerode(gameState.diffI,se);
%figure, imshow(erode);
se2 = strel('disk', 10);
gameState.dilute = imdilate(gameState.erode, se2);
%figure, imshow(dilute);

%% Fill Image
gameState.fillImage = imfill(gameState.dilute, 'holes');
figure, imshow(gameState.fillImage);

%% Get Area and Centroid Information
gameState.props = regionprops(gameState.fillImage);

%% Labels each Washer by their number
centroidNumber(gameState.snapShot, gameState.props);

%% Labels where program is getting RGB value for each washer
rgbPoints(gameState.snapShot, gameState.props);

%% Determines number of BLUE Washers
gameState.blueWasher = getBlueWasher(gameState.snapShot, gameState.props);

if (gameState.blueWasher(1) == 0)
    clear all;
    close all;
    clc;
    imaqreset;
    fprintf('No Blue Washers detected\n');
    fprintf('Program will be terminated\n');
else
    %%  Determine the angle of Washers based on Pixels 
    gameState.degrees = getWashersDegrees(gameState.props);

    %% Target PC Set Up
    tg = setTargetPC();

    %% Degree Test
    rotateMotor(gameState.degrees, gameState.blueWasher, tg);

    %% Stop Simulink
    tg.stop;
end

% --- Executes on button press in allColors.
function allColors_Callback(hObject, eventdata, handles)
%%
clear all;
close all;
clc;
imaqreset;
fprintf('User chose All Washers\n');
%% Set Up Webcam
gameState.cam = webcam('HP USB Webcam');
preview(gameState.cam);

%% Align Board with Camera
% while (1)
%     back = snapshot(cam);
%     imshow(back);
%     hold on;
%     plot(320, 240, 'rx');
%     hold off;
% end

%% Get Background Image
gameState.background = getBackgroundImage(gameState.cam);

%% Get SnapShot Image

gameState.snapShot = getSnapshotImage(gameState.cam);

%% Get Images and Turn it to Gray Scale

gameState.backgroundG = rgb2gray(gameState.background);
gameState.snapShotG = rgb2gray(gameState.snapShot);

%% Take difference between Backgroun and Snapshot
gameState.difference = gameState.backgroundG - gameState.snapShotG;
figure, imshow(gameState.difference);

%% Obtain Gray Scale of Difference
gameState.diffI = im2bw(gameState.difference, 0.15);
%imshow(diffI);

%% Erosion and Dilution
se = strel('disk', 3);
gameState.erode = imerode(gameState.diffI,se);
%figure, imshow(erode);
se2 = strel('disk', 10);
gameState.dilute = imdilate(gameState.erode, se2);
%figure, imshow(dilute);

%% Fill Image
gameState.fillImage = imfill(gameState.dilute, 'holes');
figure, imshow(gameState.fillImage);

%% Get Area and Centroid Information
gameState.props = regionprops(gameState.fillImage);

%% Labels each Washer by their number
centroidNumber(gameState.snapShot, gameState.props);

%% Labels where program is getting RGB value for each washer
rgbPoints(gameState.snapShot, gameState.props);

%% Determines number of ALL Washers
gameState.allWashers = getAllWashers(gameState.snapShot, gameState.props);

if (gameState.allWashers(1) == 0)
    clear all;
    close all;
    clc;
    imaqreset;
    fprintf('No Green Washers detected\n');
    fprintf('Program will be terminated\n');
else
    %%  Determine the angle of Washers based on Pixels 
    gameState.degrees = getWashersDegrees(gameState.props);

    %% Target PC Set Up
    tg = setTargetPC();

    %% Degree Test
    rotateMotorAll(gameState.degrees, gameState.allWashers, tg);

    %% Stop Simulink
    tg.stop;
end