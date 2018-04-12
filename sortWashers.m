function sortWashers(initialTable, finalTable, tg)

    % Sets up the Arm to initial position
    [a, s1, s2] = arduinoSetup();
    
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
                        
                        %Moves arm to the board
                        writePosition(s1, 0);
                        pause(3);
                        
                        %Moves arm down to pick up washer
                        writePosition(s2, 0.9);
                        pause(2);
                        
                        %Calculate weight of picked up washer
                        %weightPicked = loadCellFunction
                        
                        %Moves arm to initial position
                        writePosition(s2, 1);
                        pause(2);
                        
                        
                        degree = 0;
                        
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        pause(5);
                        if ((weightPicked < 10) && (washerWeight == 1))
                              desiredDegree = finalTable{c1, 1};
                            
                              %Looks for the location on the desired degree
                              %on the Initial table
                              for c3 = 1:10
                                if (initialTable{c2, 1} == desiredDegree)
                                    colorOnDesiredDegree = initialTable{c3, 2};
                                    break;
                                end
                              end
                              
                              %Spot is empty
                              if (strcmp(colorOnDesiredDegree, '') == 1)

                                  %Move arm down and pick up washer
                                  writePosition(s2, 0.9);

                                  %Move arm up
                                  writePosition(s2, 1);


                                  %Go to empty spot
                                  tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);
                                  pause(2);

                                  %Drop the washer
                                  writePosition(s2, 0.9);


                                  %Delete position of washer in the initial
                                  %Table
                                  initialTable{c3, 2} = '';

                              %Spot is filled
                              else
                                  %Search for an empty spot
                                  for c4 = 1:10
                                      if (strcmp(initialTable{c4, 2}, '') == 1)
                                          foundEmpty = 1;
                                          break;
                                      end
                                  end

                                  %Found empty spot
                                  if (foundEmpty == 1)
                                      emptyDegree = initialTable{c4, 1};

                                      %Go to filled spot
                                      tg.setparam(tg.getparamid('Degree', 'Value'), desiredDegree);

                                      %Pick up washer
                                      writePosition(s2, 0.9);
                                      pause(2);
                                      
                                      %Move arm up
                                      writePosition(s2, 1);
                                      pause(2);
                                      
                                      %Move washer to empty spot 
                                      tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);

                                      %Drop the washer
                                      writePosition(s2, 0.9);
                                      pause(2);
                                      
                                      %Move arm up
                                      writePosition(s2, 1);
                                      pause(2);
                                      
                                      %Modify initial table 
                                      initialTable{c4, 2} = colorOnDesiredDegree;

                                      %Delete the position of washer in initial
                                      %Table
                                      initialTable{c3, 2} = '';
                                      
                                  else
                                      fprintf('No spots open\n');
                                      fprintf('Program will be terminated\n');
                                  end

                              end
                                  
                        %Erase value from original 
                        elseif ((weightPicked > 10) && (weightPicked  < 15) && (weight > 10) && (weight < 15))
                        %Level two picked and moved
                        %Erase value from original
                        elseif ((weightPicked > 15) && (weight > 15))
                        %Level three picked and moved
                        %Erase value from original
                        end
                    end
                end
            end
        end
    end
    writePosition(s1, 1);
    pause(3);
    writePosition(s2, 1);
    pause(3);
    clear a s1 s2;
end