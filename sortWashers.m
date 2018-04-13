function sortWashers(initialTable, finalTable, tg)

    % Sets up the Arm to initial position
    [a, s1, s2] = arduinoSetup();
    degreeArray = [-25, -55, -88, -130, -162, 10, 40, 85, 130, 160];
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
                        degree = initialTable{c2}{3};
                        
                        %Rotates motor to the corresponding degree
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        pause(3);
                        
                        degree2 = initialTable{c2}{1};
                        %Moves arm to the board
                        if ((degree2 == -55) || (degree2 == -130) || ...
                            (degree2 == 10) || (degree2 == 85) || ...
                            (degree2 == 160))
                            
                            writePosition(s1, 0);
                            pause(3);
                        else
                            writePosition(s1, 0.4);
                            pause(3);
                        end
                        
                        %Moves arm down to pick up washer
                        writePosition(s2, 0.95);
                        pause(3);
                        
                        %tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                        %tg.setparam(tg.getparamid('magnetDrop','Value'), 0);
                        
                        %Calculate weight of picked up washer
                        %weightPicked = loadCellFunction
                        
                        %Moves arm to initial position
                        writePosition(s2, .99);
                        pause(3);
                        
                        %Dummy asked user for weightPicked
                        weightPicked = input('Enter weight: ');
                        
                       
                        if ((weightPicked == 1) && (washerWeight == 1))
                              degreeToGo = degreeArray(c1);
                            
                              %Looks for the location on the desired degree
                              %on the Initial table
                              for c3 = 1:10
                                if (degreeArray(c3) == degreeToGo)
                                    colorOnDesiredDegree = initialTable{c3}{2};
                                    break;
                                end
                              end
                              
                              %Spot is empty
                              if (strcmp(colorOnDesiredDegree, '') == 1)
                                  fprintf('%d\n', c3);
                                  degree = initialTable{c3}{1};
                                  %Go to empty spot
                                  tg.setparam(tg.getparamid('Degree','Value'), degree);
                                  pause(3);
                                
                                  %Moves arm to the board
                                  if ((degreeToGo == -55) || (degreeToGo == -130) || ...
                                      (degreeToGo == 10) || (degreeToGo == 85) || ...
                                      (degreeToGo == 160))

                                      writePosition(s1, 0);
                                      pause(3);
                                  else
                                      writePosition(s1, 0.4);
                                      pause(3);
                                  end

                                  %Drop the washer
                                  writePosition(s2, 0.95);
                                  pause(3);
                                  %tg.setparam(tg.getparamid('magnetDrop','Value'), 1);
                                  %tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                  pause(3);
                                  
                                  %Move up arm
                                  writePosition(s2, .99);
                                  pause(3);
                                  %tg.setparam(tg.getparamid('magnetDrop','Value'), 0);
                                  pause(3);

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
                                      degree = initialTable{c3}{1};
                                      emptyDegree = initialTable{c4}{1};
                                      fprintf('Here2\n');

                                      %Go to filled spot
                                      tg.setparam(tg.getparamid('Degree','Value'), degree);
                                      pause(3);
                                      
                                      degreeToGo = degree;
                                      %Moves arm to the board
                                      if ((degreeToGo == -55) || (degreeToGo == -130) || ...
                                        (degreeToGo == 10) || (degreeToGo == 85) || ...
                                        (degreeToGo == 160))

                                        writePosition(s1, 0);
                                        pause(3);
                                      else
                                        writePosition(s1, 0.4);
                                        pause(3);
                                      end
                                      
                                      %Pick up washer
                                      writePosition(s2, 0.95);
                                      pause(3);
                                      
                                      %Move arm up
                                      writePosition(s2, .99);
                                      pause(3);
                                      
                                      %Move washer to empty spot 
                                      tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                      pause(3);
                                      
                                      degreeToGo = emptyDegree;
                                      %Moves arm to the board
                                      if ((degreeToGo == -55) || (degreeToGo == -130) || ...
                                        (degreeToGo == 10) || (degreeToGo == 85) || ...
                                        (degreeToGo == 160))

                                        writePosition(s1, 0);
                                        pause(3);
                                      else
                                        writePosition(s1, 0.4);
                                        pause(3);
                                      end
                                      
                                      %Drop the washer
                                      writePosition(s2, 0.9);
                                      pause(3);
                                      
                                      %Move arm up
                                      writePosition(s2, .95);
                                      pause(3);
                                     
                                      %Degree of the Washer to be weighted
                                        degree = initialTable{c2}{3};

                                        %Rotates motor to the corresponding degree
                                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                                        pause(3);

                                        degree2 = initialTable{c2}{1};
                                        %Moves arm to the board
                                        if ((degree2 == -55) || (degree2 == -130) || ...
                                            (degree2 == 10) || (degree2 == 85) || ...
                                            (degree2 == 160))

                                            writePosition(s1, 0);
                                            pause(3);
                                        else
                                            writePosition(s1, 0.4);
                                            pause(3);
                                        end

                                        %Moves arm down to pick up washer
                                        writePosition(s2, 0.95);
                                        pause(3);
                                        
                                        %Move arm up
                                        writePosition(s2, 0.99);
                                        pause(2);
                                        
                                        %Go to filled spot
                                        degree = initialTable{c3}{1};
                                      tg.setparam(tg.getparamid('Degree','Value'), degree);
                                      pause(3);
                                      
                                      degreeToGo = degree;
                                      %Moves arm to the board
                                      if ((degreeToGo == -55) || (degreeToGo == -130) || ...
                                        (degreeToGo == 10) || (degreeToGo == 85) || ...
                                        (degreeToGo == 160))

                                        writePosition(s1, 0);
                                        pause(3);
                                      else
                                        writePosition(s1, 0.4);
                                        pause(3);
                                      end

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
    pause(3);
    writePosition(s1, 1);
    pause(3);
    clear a s1 s2;
    pause(3);
    tg.setparam(tg.getparamid('Degree', 'Value'), 0);
    pause(3);
end