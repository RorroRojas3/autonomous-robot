
function rotateMotor(degrees, redWasher, tg)
    while(1)
        %Menu is displayed
        fprintf('Enter: 1) For All Selected Color Washers | 2) For Specific Selected Color Washer | 3) To Exit | \n');
        command = input('Enter: ');
        % Motor will rotate to the all washers of desired color selected
        if (command == 1)
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
        % Motor will rotate to specific Washer
        elseif (command == 2)
            fprintf('Select one of the of these Washers: ');
            for c1 = 1:numel(redWasher)
                fprintf('%d ', redWasher(c1));
            end
            fprintf('\n');
            command2 = input('Input number of Washer: ');
            true = 0;
            for c1 = 1:numel(redWasher)
                if (command2 == redWasher(c1))
                    true = 1;
                    break;
                end
            end
            if (true == 1)
                tg.setparam(tg.getparamid('Degree','Value'), degrees(command2));
                pause(3);
                tg.setparam(tg.getparamid('Degree','Value'), 0);
                pause(3)
            else
                fprintf('Error, Washer selected is Invalid\n');
                tg.setparam(tg.getparamid('Degree','Value'), 0);
            end
        % User decided to terminate program and breaks from loop
        elseif (command == 3)
            fprintf('Program terminated\n');
            break;
        end
    end
end