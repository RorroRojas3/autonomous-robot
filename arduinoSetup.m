function [s1, s2] = arduinoSetup()

    %MATLAB recognizes and initializes ARDUINOUNO
    a = arduino;

    %Sets ARDUINO pins and maximum and minimum traveling or Servo
    s1 = servo(a, 'D10', 'MaxPulseDuration', 2.55e-3, 'MinPulseDuration', 6.4e-4);
    s2 = servo(a, 'D9', 'MaxPulseDuration', 2.3e-3, 'MinPulseDuration', 2.55e-3);
    
    %Moves arm to the back 
    writePosition(s1, 1);
    
    %Moves arm up to initial position
    %writePosition(s2, 1);
end