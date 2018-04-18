%% SETUP

tg =xpc; % MUST BE DECLARED AT THE START OF EVERY FUNCTION USING xPC CMDS
filename = 'PID_LoadCell_Magnet';

%only need load or rtwbuild, rtwbuild is redundant if you haven't made any
%changes to the model file and only need to load the .dlm file
if strcmp(tg.application,filename)
    tg.load(filename); 
else
    rtwbuild(filename);
end
    
tg.start;

%% CODE
while (1)
    % Obtains value of the load cell
    %loadCell = tg.getparam(tg.getparamid('Q4 AD','Amplitude'));
    loadCell = tg.getparamid('loadCell','Value');
    %Constant value of voltage given to Load Cell
    %voltageToCell = 7;
    %Constant value of voltage with NO weight on Load Cell
    offset = .021;  %2.376
    %Constant value of voltage with WASHER weight on Load Cell
    measuredV = 0.001;        %2.378;      
    %Solve constant k
    k = 5 / ((measuredV - offset) / 5);
    fprintf("K = %.3f\n", k);
    %Measures the weight on the Load Cell
    weight = (k * ((loadCell - offset)/ 7));
    %averageWeightNothing = 3.998;
    % If the value of the load cell is greater than # then electromagnet
    % will pick up the washer
%     if (weight >= 15)
%         tg.setparam(tg.getparamid('DC Input','Value'), 4);
%     % If value of load cell is less than # then electromagnet will not 
%     % pick up the washer
%     else
%         tg.setparam(tg.getparamid('DC Input','Value'), 0);
%     end
    
    fprintf('Load Cell Input: %.6f\n',loadCell);
    fprintf('Weight: %.6f\n',weight);
    pause(1);
end

%% STOP

tg.stop;