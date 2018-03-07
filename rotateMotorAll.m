function rotateMotorAll(degrees, washers, tg)
    while(1)
        %Menu is displayed
        fprintf('Enter: 1) For All Washers | 2) For Specific Washer | 3) To Exit | \n');
        command = input('Enter: ');
        % Motor will rotate to the all washers of desired color selected
        if (command == 1)
            for c1 = 1:numel(degrees)
                tg.setparam(tg.getparamid('Degree','Value'), degrees(c1));
                pause(3);
                tg.setparam(tg.getparamid('Degree','Value'), 0);
                pause(3);
            end
        % Motor will rotate to specific Washer
        elseif (command == 2)
            fprintf('Select one of the of these Washers: ');
            for c1 = 1:numel(washers)
                fprintf('%d ', washers(c1));
            end
            fprintf('\n');
            command2 = input('Input number of Washer: ');
            true = 0;
            for c1 = 1:numel(washers)
                if (command2 == washers(c1))
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
        end
    end

end