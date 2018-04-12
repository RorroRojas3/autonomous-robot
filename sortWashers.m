function sortWashers(initialTable, finalTable, tg)

    % Sets up the Arm to initial position
    [a, s1, s2] = arduinoSetup();
    degreeArray = [-13, -40, -88, -130, -162, 30, 65, 95, 125, 160];
    for c1 = 1:10
        color = finalTable{c1, 2};
        
        %Checks if the user input a color in certain degree
        if ((strcmp(color, '')) == 0)
            for c2 = 1:10
                color2 = initialTable{c2}{2};
                
                %Compares the initial color and the color input by user
                if ((strcmp(color, color2)) == 1)
                    washerWeight = finalTable(c1, 3);
                    
                    %Checks that the user has input a weight of the washer
                    %desired to be moved 
                    if ((strcmp(washerWeight, '')) == 0)
                        
                        washerWeight = str2double(washerWeight);
                        
                        %Degree of the Washer to be weighted
                        degree = initialTable{c2}{1};
                        
                        %Rotates motor to the corresponding degree
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        pause(5);
                        
                        %Moves arm to the board
                        if ((degree == -13) || (degree == -88) || (degree == -162) || (degree == 30) || (degree == 95) || (degree == 160))
                            
                            writePosition(s1, 0);
                            pause(5);
                        else
                            writePosition(s1, 0.4);
                            pause(5);
                        end
                        
                        %Moves arm down to pick up washer
                        writePosition(s2, 0.85);
                        pause(5);
                        
                        tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                        tg.setparam(tg.getparamid('magnetDrop','Value'), 0);
                        
                        %Calculate weight of picked up washer
                        %weightPicked = loadCellFunction
                        
                        %Moves arm to initial position
                        writePosition(s2, .99);
                        pause(5);
                        
                        %Dummy asked user for weightPicked
                        weightPicked = input('Enter weight: ');
                        
                       
                        if ((weightPicked < 10) && (washerWeight == 1))
                              desiredDegree = degreeArray(c1);
                            
                              %Looks for the location on the desired degree
                              %on the Initial table
                              for c3 = 1:10
                                if (degreeArray(c3) == desiredDegree)
                                    colorOnDesiredDegree = initialTable{c3}{2};
                                    break;
                                end
                              end
                              
                              %Spot is empty
                              if (strcmp(colorOnDesiredDegree, '') == 1)

                                 
                                  %Go to empty spot
                                  tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);
                                  pause(5);
                                  
                                  %Moves arm to the board
                                  if ((desiredDegree == -13) || (desiredDegree == -88) || (desiredDegree == -162) || (desiredDegree == 30) || (desiredDegree == 95) || (desiredDegree == 160))

                                      writePosition(s1, 0.4);
                                      pause(5);
                                  else
                                      writePosition(s1, 0);
                                      pause(5);
                                  end

                                  %Drop the washer
                                  writePosition(s2, 0.95);
                                  pause(5);
                                  tg.setparam(tg.getparamid('magnetDrop','Value'), 1);
                                  tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                  pause(5);
                                  
                                  %Move up arm
                                  writePosition(s2, .99);
                                  pause(5);
                                  %tg.setparam(tg.getparamid('magnetDrop','Value'), 0);
                                  pause(5);

                                  %Delete position of washer in the initial
                                  %Table
                                  initialTable{c2}{2} = '';
                                  fprintf('Here\n');
                              %Spot is filled
                              else
                                  %Search for an empty spot
                                  for c4 = 1:10
                                      if (strcmp(initialTable{c4}{2}, '') == 1)
                                          foundEmpty = 1;
                                          break;
                                      end
                                  end

                                  %Found empty spot
                                  if (foundEmpty == 1)
                                      emptyDegree = degreeArray(c4);
                                      fprintf('Here2\n');

                                      %Go to filled spot
                                      tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);
                                      pause(5);
                                      
                                      %Pick up washer
                                      writePosition(s2, 0.9);
                                      pause(3);
                                      
                                      %Move arm up
                                      writePosition(s2, .99);
                                      pause(3);
                                      
                                      %Move washer to empty spot 
                                      tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                      pause(5);
                                      
                                      %Drop the washer
                                      writePosition(s2, 0.9);
                                      pause(2);
                                      
                                      %Move arm up
                                      writePosition(s2, .99);
                                      pause(2);
                                      
                                      %Modify initial table 
                                      initialTable{c4}{2} = colorOnDesiredDegree;

                                      %Delete the position of washer in initial
                                      %Table
                                      initialTable{c3}{2} = '';
                                      foundEmpty = 0;
                                  else
                                      fprintf('No spots open\n');
                                      fprintf('Program will be terminated\n');
                                  end

                              end
                                 
%                         elseif ((weightPicked > 10) && (weightPicked  < 15) && (washerWeight == 2))
%                             %Level two picked and moved
%                             %Erase value from original
%                         elseif ((weightPicked > 15) && (washerWeight == 2))
%                             %Level three picked and moved
%                             %Erase value from original
                        end
                    end
                end
            end
        end
    end
    writePosition(s2, .99);
    pause(5);
    writePosition(s1, 1);
    pause(5);
    clear a s1 s2;
    pause(2);
    tg.setparam(tg.getparamid('Degree', 'Value'), 0);
    pause(2);
end