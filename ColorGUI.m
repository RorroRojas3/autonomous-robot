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

% --- Executes on button press in greenColors.
function greenColors_Callback(hObject, eventdata, handles)
% hObject    handle to greenColors (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf("User Chose Green\n");

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

% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


