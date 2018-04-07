function sortWashers(initial, final, tg)
    servo = arduinoSetup();
    for c1 = 1:10
        color = final{c1, 2};
        if ((strcmp(color, '')) == 0)
            for c2 = 1:10
                color2 = initial{c2}{2};
                if ((strcmp(color, color2)) == 1)
                    weight = final(c1, 3);
                    weight = str2double(weight);
                    if ((strcmp(weight, '')) == 0)
                        fprintf('Here\n');
                        %Degree of the Washer to be weighted
                        degree = initial{c2}{1};
                        %Rotates motor to the corresponding degree
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        writePosition(servo, 0);
                        %Calculate weight of picked up washer
                        %weightPicked = loadCellFunction
                        pause(3);
                        degree = 0;
                        %writePosition(servo, 1);
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        %pause(3);
%                         if ((weightPicked < 10) && (weight < 10))
%                             %Level one picked up and moved
%                             %Erase value from original 
%                         elseif ((weightPicked > 10) && (weightPicked  < 15) && (weight > 10) && (weight < 15))
%                             %Level two picked and moved
%                             %Erase value from original
%                         elseif ((weightPicked > 15) && (weight > 15))
%                             %Level three picked and moved
%                             %Erase value from original
%                         end
                    end
                end
            end
        end
    end
    writePosition(servo, 1);
    pause(3);
end