function sortWashers(initial, final, tg)

    % Sets up the Arm to initial position
    [s1, s2] = arduinoSetup();
    
    for c1 = 1:10
        color = final{c1, 2};
        
        %Checks if the user input a color in certain degree
        if ((strcmp(color, '')) == 0)
            for c2 = 1:10
                color2 = initial{c2}{2};
                
                %Compares the initial color and the color input by user
                if ((strcmp(color, color2)) == 1)
                    weight = final(c1, 3);
                    weight = str2double(weight);
                    
                    %Checks that the user has input a weight of the washer
                    %desired to be moved 
                    if ((strcmp(weight, '')) == 0)
                        %Degree of the Washer to be weighted
                        degree = initial{c2}{1};
                        
                        %Rotates motor to the corresponding degree
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        
                        %Moves arm to the board
                        writePosition(s1, 0);
                        
                        %Moves arm up and down
                        
                        %Calculate weight of picked up washer
                        %weightPicked = loadCellFunction
                        
                        
                        pause(5);
                        
                        
                        degree = 0;
                        %writePosition(s1, 1);
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        pause(5);
% %                         if ((weightPicked < 10) && (weight < 10))
%                               desiredDegree = final{c1, 1};
%                             
%                               %Looks for the location on the desired
%                               %degree on the initial Table
%                               for c3 = 1:10
%                                 if (initial{c2, 1} == desiredDegree)
%                                     colorOnDesiredDegree = initial{c3, 2};
%                                     break;
%                                 end
%                               end
%                               
% %                             %Spot is empty
%                               if (strcmp(colorOnDesiredDegree, '') == 1)
%                                   %Pick up washer again
%                                   
%                                   %Go to empty spot
%                                   tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);
%                                   pause(2);
%                                   
%                                   %Drop the washer
%                                   
%                                   
%                                   %Delete the position of washer in initial
%                                   %Table
%                                   initial{c3, 2} = '';
%                                   
%                               %Spot is filled
%                               else
%                                   %Search for an empty spot
%                                   for c4 = 1:10
%                                       if (strcmp(initial{c4, 2}, '') == 1)
%                                           break;
%                                       end
%                                   end
%                                   emptyDegree = initial{c4, 1};
%                                   
%                                   %Go to filled spot
%                                   tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);
%                                   
%                                   %Pick up washer
%                                   
%                                   %Move washer to empty spot 
%                                   tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
%                                   
%                                   %Drop the washer
%                                   
%                                   %Modify initial table 
%                                   initial{c4, 2} = colorOnDesiredDegree;
%                                   
%                                   %Go to Washer 
%                                   tg.setparam(tg.getparamid('Degree', 'Value'), degree);
%                                   
%                                   %Pick up Washer
%                                   
%                                   tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);
%                                   
%                                   %Drop Washer
%                                   
%                                   %Delete the position of washer in initial
%                                   %Table
%                                   initial{c3, 2} = '';
%                                   
%                                   
%                               end
%                                   
%                         
% %                             %Erase value from original 
% %                         elseif ((weightPicked > 10) && (weightPicked  < 15) && (weight > 10) && (weight < 15))
% %                             %Level two picked and moved
% %                             %Erase value from original
% %                         elseif ((weightPicked > 15) && (weight > 15))
% %                             %Level three picked and moved
% %                             %Erase value from original
% %                         end
                    end
                end
            end
        end
    end
    writePosition(s1, 1);
    pause(3);
end