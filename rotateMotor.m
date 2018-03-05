function rotateMotor(degrees, redWasher, tg)
    for c1 = 1:numel(degrees)
        for c2 = 1:numel(redWasher)
            if  (c1 == redWasher(c2))
                tg.setparam(tg.getparamid('Degree','Value'), degrees(c1));
                pause(3);
                tg.setparam(tg.getparamid('Degree','Value'), 0);
                pause(3);
            end
        end
    end

end