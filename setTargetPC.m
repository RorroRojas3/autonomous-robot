function tg = setTargetPC()
    tg = xpc; % MUST BE DECLARED AT THE START OF EVERY FUNCTION USING xPC CMDS
    %filename = 'dc_motor_encoder_hardware_simulated';
    filename = 'PIDControl';
    %only need load or rtwbuild, rtwbuild is redundant if you haven't made any
    %changes to the model file and only need to load the .dlm file
    if strcmp(tg.application,filename)
        tg.load(filename); 
    else
        rtwbuild(filename);
    end

    tg.start;
end