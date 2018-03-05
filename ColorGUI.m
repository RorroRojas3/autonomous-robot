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

% Last Modified by GUIDE v2.5 04-Mar-2018 17:06:46

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
% hObject    handle to redColors (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf("User Chose Red\n");
%%
close all;
clear all;
clc;
imaqreset;
close

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
   plot(floor(properties(c1).Centroid(1) + halfRadius), floor(properties(c1).Centroid(2)), 'rx');
   plot(floor(properties(c1).Centroid(1)), floor(properties(c1).Centroid(2) - halfRadius), 'rx');
   plot(floor(properties(c1).Centroid(1)), floor(properties(c1).Centroid(2) + halfRadius), 'rx');
end
plot(640/2, 480/2, 'rx');
hold off;

%%  Determines the color of each washer
c2 = 1;
for c1 = 1:numel(properties)
    radius = sqrt(properties(c1).Area / pi);
    halfRadius = radius / 2;
    % Obtains Average Red value of current Washer
    redColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) - halfRadius + 2) , floor(properties(c1).Centroid(1) - 7) , 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) - halfRadius + 2) , floor(properties(c1).Centroid(1) + 7) , 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius + 2) , floor(properties(c1).Centroid(1) - 7) , 1);
    fprintf('%d\n', redColor);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius + 2) , floor(properties(c1).Centroid(1) + 7) , 1);
    fprintf('%d\n', redColor);
    % Obtains Average Green value of current Washer
    greenColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 2);
    % Obtains Average Blue value of current Washer
    blueColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 3);
    blueColor = blueColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 3);
    blueColor = blueColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 3);
    blueColor = blueColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 3);
    fprintf('Washer #%d | R(%d), G(%d), B(%d) | ', c1, redColor, greenColor, blueColor);
%     %If color is RED
%     if ((redColor >= 58) && (greenColor >=0) && (greenColor <=90) && (blueColor >= 21) && (blueColor <= 100))
%         fprintf("RED\n");
%         redWasher(c2) = c1;
%     % IF Color is Blue
%     elseif ((redColor >=44) && (redColor <= 72) && (greenColor >=50) && (greenColor <= 92) && (blueColor >= 61))
%         fprintf('BLUE\n');
%     else
%         fprintf('GREEN\n');
%     end
%     c2 = c2 + 1;
    if ((redColor > greenColor) && (redColor > blueColor))
        fprintf("Red\n");
        redWasher(c2) = c1;
    elseif ((greenColor > redColor) && (greenColor > blueColor))
        fprintf("Green\n");
    else
        fprintf("Blue\n");
    end
    c2 = c2 + 1;
end
fprintf('\n');

%%  Determine the angle of Washers based on Pixels 
for c1= 1:numel(properties)
    centerX = 320;
    centerY = 240;
    currentX = properties(c1).Centroid(1);
    currentY = properties(c1).Centroid(2);
    
    if (currentX > centerX)
        x(c1) = abs(centerX - currentX);
    else
        x(c1) =  currentX - centerX;
    end
    
    if (currentY < centerY)
        y(c1) = abs(centerY - currentY);
    else
        y(c1) = centerY - currentY;
    end
  
    if ((y(c1) >= 0) && (x(c1) <= 0))
        degrees(c1) = -180 + atand(abs(y(c1) / x(c1)));
    elseif ((y(c1) >= 0) && (x(c1) >= 0))
        degrees(c1) = -1 * atand(abs(y(c1) / x(c1))); 
    elseif ((y(c1) <= 0) && (x(c1) >= 0))
        degrees(c1) = atand(abs(y(c1) / x(c1)));
    else
        degrees(c1) = 180 - atand(abs(y(c1) / x(c1)));
    end
   
    fprintf('Washer #%d | X: %.3f | Y: %.3f | Degree: %.3f\n', c1, x(c1), y(c1), degrees(c1));
end

%% Target PC Set Up

tg =xpc; % MUST BE DECLARED AT THE START OF EVERY FUNCTION USING xPC CMDS
filename = 'dc_motor_encoder_hardware_simulated';

%only need load or rtwbuild, rtwbuild is redundant if you haven't made any
%changes to the model file and only need to load the .dlm file
if strcmp(tg.application,filename)
    tg.load(filename); 
else
    rtwbuild(filename);
end
    
tg.start;

%% Degree Test

for c1 = 1:numel(degrees)
    for c2 = 1:numel(redWasher)
        if (c1 == redWasher(c2))
            tg.setparam(tg.getparamid('Degree','Value'), degrees(c1));
            pause(3);
            tg.setparam(tg.getparamid('Degree','Value'), 0);
            pause(3);
        end
    end
end

% --- Executes on button press in greenColors.
function greenColors_Callback(hObject, eventdata, handles)
% hObject    handle to greenColors (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf("User Chose Green\n");
fprintf("User Chose Red\n");
%%
close all;
clear all;
clc;
imaqreset;
close

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
   plot(floor(properties(c1).Centroid(1) + halfRadius), floor(properties(c1).Centroid(2)), 'rx');
   plot(floor(properties(c1).Centroid(1)), floor(properties(c1).Centroid(2) - halfRadius), 'rx');
   plot(floor(properties(c1).Centroid(1)), floor(properties(c1).Centroid(2) + halfRadius), 'rx');
   plot(floor(properties(c1).Centroid(1) - halfRadius) + 2, floor(properties(c1).Centroid(2)) - 7, 'rx');
   plot(floor(properties(c1).Centroid(1) - halfRadius) + 2, floor(properties(c1).Centroid(2)) + 7, 'rx');
   plot(floor(properties(c1).Centroid(1) + halfRadius) + 2, floor(properties(c1).Centroid(2)) - 7, 'rx');
   plot(floor(properties(c1).Centroid(1) + halfRadius) + 2, floor(properties(c1).Centroid(2)) + 7, 'rx');
end
plot(640/2, 480/2, 'rx');
hold off;

%%  Determines the color of each washer
c2 = 1;
for c1 = 1:numel(properties)
    radius = sqrt(properties(c1).Area / pi);
    halfRadius = radius / 2;
    % Obtains Average Red value of current Washer
    redColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 2, floor(properties(c1).Centroid(1)) - 7, 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 2, floor(properties(c1).Centroid(1)) + 7, 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius) + 2, floor(properties(c1).Centroid(1)) - 7, 1);
    redColor = redColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius) + 2, floor(properties(c1).Centroid(1)) + 7, 1);
    % Obtains Average Green value of current Washer
    greenColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 1, floor(properties(c1).Centroid(1)) - 7, 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 1, floor(properties(c1).Centroid(1)) + 7, 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius) + 1, floor(properties(c1).Centroid(1)) - 7, 2);
    greenColor = greenColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius) + 1, floor(properties(c1).Centroid(1)) + 7, 2);
    
    % Obtains Average Blue value of current Washer
    blueColor = snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 3);
    blueColor = blueColor + snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 3);
    blueColor = blueColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 3);
    blueColor = blueColor + snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 3);
    fprintf('Washer #%d | R(%d), G(%d), B(%d) | ', c1, redColor, greenColor, blueColor);
%     %If color is RED
%     if ((redColor >= 58) && (greenColor >=0) && (greenColor <=90) && (blueColor >= 21) && (blueColor <= 100))
%         fprintf("RED\n");
%         redWasher(c2) = c1;
%     % IF Color is Blue
%     elseif ((redColor >=44) && (redColor <= 72) && (greenColor >=50) && (greenColor <= 92) && (blueColor >= 61))
%         fprintf('BLUE\n');
%     else
%         fprintf('GREEN\n');
%     end
%     c2 = c2 + 1;
    if ((redColor > greenColor) && (redColor > blueColor))
        fprintf("Red\n");
    elseif ((greenColor > redColor) && (greenColor > blueColor))
        fprintf("Green\n");
        greenWasher(c2) = c1;
    else
        fprintf("Blue\n");
    end
    c2 = c2 + 1;
end
fprintf('\n');

%%  Determine the angle of Washers based on Pixels 
for c1= 1:numel(properties)
    centerX = 320;
    centerY = 240;
    currentX = properties(c1).Centroid(1);
    currentY = properties(c1).Centroid(2);
    
    if (currentX > centerX)
        x(c1) = abs(centerX - currentX);
    else
        x(c1) =  currentX - centerX;
    end
    
    if (currentY < centerY)
        y(c1) = abs(centerY - currentY);
    else
        y(c1) = centerY - currentY;
    end
  
    if ((y(c1) >= 0) && (x(c1) <= 0))
        degrees(c1) = -180 + atand(abs(y(c1) / x(c1)));
    elseif ((y(c1) >= 0) && (x(c1) >= 0))
        degrees(c1) = -1 * atand(abs(y(c1) / x(c1))); 
    elseif ((y(c1) <= 0) && (x(c1) >= 0))
        degrees(c1) = atand(abs(y(c1) / x(c1)));
    else
        degrees(c1) = 180 - atand(abs(y(c1) / x(c1)));
    end
   
    fprintf('Washer #%d | X: %.3f | Y: %.3f | Degree: %.3f\n', c1, x(c1), y(c1), degrees(c1));
end

%% Target PC Set Up

tg =xpc; % MUST BE DECLARED AT THE START OF EVERY FUNCTION USING xPC CMDS
filename = 'dc_motor_encoder_hardware_simulated';

%only need load or rtwbuild, rtwbuild is redundant if you haven't made any
%changes to the model file and only need to load the .dlm file
if strcmp(tg.application,filename)
    tg.load(filename); 
else
    rtwbuild(filename);
end
    
tg.start;

%% Degree Test

for c1 = 1:numel(degrees)
    for c2 = 1:numel(greenWasher)
        if (c1 == greenWasher(c2))
            tg.setparam(tg.getparamid('Degree','Value'), degrees(c1));
            pause(3);
            tg.setparam(tg.getparamid('Degree','Value'), 0);
            pause(3);
        end
    end
end

% --- Executes on button press in blueColors.
function blueColors_Callback(hObject, eventdata, handles)
% hObject    handle to blueColors (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf("User Chose Blue\n");

% --- Executes on button press in Yellow.
function Yellow_Callback(hObject, eventdata, handles)
% hObject    handle to Yellow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf("User Chose Yellow\n");


% --- Executes on button press in alignCamera.
function alignCamera_Callback(hObject, eventdata, handles)
% hObject    handle to alignCamera (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
clear all;
close all;
clc;
imaqreset;
cam = webcam('HP USB Webcam');
while (1)
    back = snapshot(cam);
    imshow(back);
    hold on;
    plot(320, 240, 'rx');
    hold off;
end

tg.stop;

% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


