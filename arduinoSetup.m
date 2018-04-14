function [a, s1, s2] = arduinoSetup()

    %MATLAB recognizes and initializes ARDUINOUNO
    a = arduino;

    %Sets ARDUINO pins and maximum and minimum traveling or Servo
    s1 = servo(a, 'D10', 'MaxPulseDuration', 2.55e-3, 'MinPulseDuration', 6.4e-4);
    s2 = servo(a, 'D9', 'MaxPulseDuration', 2.55e-3, 'MinPulseDuration', 2.3e-3);
    
    %Moves arm to original position on y-axis
    writePosition(s2, .99);
    pause(1);
    
    %Moves arm to work position on x-axis
    writePosition(s1, 1);
    pause(1);
    
end