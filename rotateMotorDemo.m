function rotateMotorDemo(degrees, washers, tg)
    firstTime = 0;
    while(1)
        %Menu is displayed
        fprintf('\nEnter: 1) For All Selected Color Washers | 2) For Specific Selected Color Washer | 3) To Exit | \n');
        command = input('Enter: ');
        % Motor will rotate to the all washers of desired color selected
        if (command == 1)
            for c1 = 1:numel(degrees)
                for c2 = 1:numel(washers)
                    if  (c1 == washers(c2))
                        if (firstTime == 0)
                            tg.setparam(tg.getparamid('Degree','Value'), degrees(c1));
                            firstTime = 1;
                            pause(3);
                        else
                            if ((washers(c2) > 0) && (washers(c2 - 1) > 0))
                                if (washers(c2 - 1) > washers(c2))   
                                    tg.setparam(tg.getparamid('Degree','Value'), washers(c2) - (washers(c2 - 1)));
                                    pause(3);
                                    if (c2 == max(washers))
                                        tg.setparam(tg.getparamid('Degree','Value'), 0);
                                    end
                                elseif (washers(c2) > washers(c2 - 1))
                                    diff = washers(c2) - (washers(c2 - 1);
                                    tg.setparam(tg.getparamid('Degree','Value'), washers(c2) + diff);
                                    pause(3);
                                    if (c2 == max(washers))
                                        tg.setparam(tg.getparamid('Degree','Value'), 0);
                                    end
                                end
                            elseif ((washers(c2) < 0) && (washers(c2 - 1) < 0))
                                if (washers(c2 - 1) < washers(c2))
                                    diff = abs(washers(c2 - 1)) - abs(washers(c2));
                                    pause(3);
                                    tg.setparam(tg.getparamid('Degree','Value'), diff);
                                    if (c2 == max(washers))
                                        tg.setparam(tg.getparamid('Degree','Value'), 0);
                                    end
                                elseif (washers(c2) < washers(c2 - 1))
                                    diff = abs(washers(c2)) - abs(washers(c2 - 1));
                                    diff = diff * -1;
                                    tg.setparam(tg.getparamid('Degree','Value'), diff);
                                    pause(3);
                                end    
                            elseif ((washers(c2) > 0) && (washers(c2 - 1) < 0))
                                sum = washers(c2) + abs(washers(c2 - 1));
                                tg.setparam(tg.getparamid('Degree','Value'), sum);
                                pause(3);
                                if (c2 == max(washers))
                                    tg.setparam(tg.getparamid('Degree','Value'), 0);
                                end
                            elseif ((washers(c2) < 0) && (washers(c2 - 1) > 0))
                                sum = washers(c2) - washers(c2 - 1);
                                tg.setparam(tg.getparamid('Degree','Value'), sum);
                                pause(3);
                                if (c2 == max(washers))
                                    tg.setparam(tg.getparamid('Degree','Value'), 0);
                                end
                            end
                                
                        end
                    end
                end
            end
        % Motor will rotate to specific Washer
        elseif (command == 2)
            fprintf('Select one of these Washers: ');
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
            break;
        end
    end
end