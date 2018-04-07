function s = arduinoSetup()

    a = arduino;
    s = servo(a, 'D10', 'MaxPulseDuration', 2.55e-3, 'MinPulseDuration', 6.4e-4);
    writePosition(s, 1);
end