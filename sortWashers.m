function sortWashers(initialTable, finalTable, tg)

    % Sets up the Arm to initial position
    [a, s1, s2] = arduinoSetup();
    degreeArray = [-25, -55, -88, -130, -162, 10, 40, 85, 130, 160];
    for c1 = 1:10
        
        finalColor = finalTable{c1, 2};
        
        %Checks if the user input a color in certain degree
        if ((strcmp(finalColor, '')) == 0)
            for c2 = 1:10
                initialColor = initialTable{c2}{2};
                %Compares the initial color and the color input by user
                if ((strcmp(finalColor, initialColor)) == 1)
                    
                    %Obtains the washer level weight (1, 2, or 3)
                    washerWeight = finalTable(c1, 3);
                    
                    %Checks that the user has input a weight of the washer
                    %desired to be moved 
                    if ((strcmp(washerWeight, '')) == 0)
                        
                        washerWeight = str2double(washerWeight);
                        
                        %Degree of the Washer to be weighted
                        degree = initialTable{c2}{3};
                        
                        %Rotates motor to the corresponding degree
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        pause(2);
                        
                        %Checks distance that arm must travel in the x-axis
                        %based on the degree value
                        degree2 = initialTable{c2}{1};
                        if ((degree2 == -55) || (degree2 == -130) || ...
                            (degree2 == 10) || (degree2 == 85) || ...
                            (degree2 == 160))
                            writePosition(s1, 0);
                            pause(2);
                        else
                            writePosition(s1, 0.4);
                            pause(2);
                        end
                        
                        %Moves arm down to pick up washer
                        writePosition(s2, 0.95);
                        pause(2);
                                          
                        %Moves arm to initial position
                        writePosition(s2, .99);
                        pause(2);
                        
                        %Dummy asked user for weightPicked
                        weightPicked = input('Enter weight: ');

                        %Checks the level of weight input by the user and
                        %the washer weight that has been picked up by the
                        %electro magnet
                        if ((weightPicked == 1) && (washerWeight == 1))
                              
                              %Degree which the washer will be
                              %moved to
                              nextDegree = degreeArray(c1);
                            
                              %Looks for the location on the desired degree
                              %on the Initial Table with the purpose of
                              %checking if the spot is either empty or
                              %filled with a colored washer
                              for c3 = 1:10
                                if (degreeArray(c3) == nextDegree)
                                    colorOnDesiredDegree = initialTable{c3}{2};
                                    break;
                                end
                              end
                              
                              %Degree which washer will be moved is empty
                              if (strcmp(colorOnDesiredDegree, '') == 1)

                                  %Obtains degree value of empty hole
                                  emptyDegree = initialTable{c3}{1};
                                  
                                  %Go to empty hole
                                  tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                  pause(2);
                                
                                  %Checks distance that arm must travel in the x-axis
                                  %based on the degree value
                                  degree2 = emptyDegree;
                                  if ((degree2 == -55) || (degree2 == -130) || ...
                                      (degree2 == 10) || (degree2 == 85) || ...
                                      (degree2 == 160))
                                      writePosition(s1, 0);
                                      pause(2);
                                  else
                                      writePosition(s1, 0.4);
                                      pause(2);
                                  end

                                  %Drop the washer
                                  writePosition(s2, 0.95);
                                  pause(2);
                                  
                                  %Move up arm
                                  writePosition(s2, .99);
                                  pause(2);
                                  
                                  %Delete position of washer in the initial
                                  %Table
                                  initialTable{c3}{2} = '';

                              %Degree which washer will be moved is not
                              %empty
                              else
                                  
                                  %Search for an empty spot on the
                                  %gameboard
                                  for c4 = 1:10
                                      if (strcmp(initialTable{c4}{2}, '') == 1)
                                          foundEmpty = 1;
                                          break;
                                      end
                                  end

                                  %An empty spot has been found in the
                                  %gameboard
                                  if (foundEmpty == 1)
                                      
                                      %Degree which washer will be moved to
                                      nextDegree = initialTable{c3}{1};
                                      
                                      %Degree with an empty spot in the
                                      %gameboard
                                      emptyDegree = initialTable{c4}{1};

                                      %Goes to the filled spot 
                                      tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                      pause(2);
                                      
                                      %Checks distance that arm must travel in the x-axis
                                      %based on the degree value
                                      degree2 = nextDegree;
                                      if ((degree2 == -55) || (degree2 == -130) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 160))
                                        writePosition(s1, 0);
                                        pause(2);
                                      else
                                        writePosition(s1, 0.4);
                                        pause(2);
                                      end
                                      
                                      %Pick up washer
                                      writePosition(s2, 0.95);
                                      pause(2);
                                      
                                      %Move arm up
                                      writePosition(s2, .99);
                                      pause(2);
                                      
                                      %Move washer to empty spot 
                                      tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                      pause(2);

                                      %Checks distance that arm must travel in the x-axis
                                      %based on the degree value
                                      degree2 = emptyDegree;
                                      if ((degree2 == -55) || (degree2 == -130) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 160))
                                        writePosition(s1, 0);
                                        pause(2);
                                      else
                                        writePosition(s1, 0.4);
                                        pause(2);
                                      end
                                      
                                      %Drop the washer
                                      writePosition(s2, 0.95);
                                      pause(3);
                                      
                                      %Move arm up
                                      writePosition(s2, .99);
                                      pause(3);
                                     
                                      %Degree of the Washer to be weighted
                                        degree = initialTable{c2}{3};

                                        %Rotates motor to the corresponding degree
                                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                                        pause(2);

                                        %Checks distance that arm must travel in the x-axis
                                        %based on the degree value
                                        degree2 = initialTable{c2}{1};
                                        if ((degree2 == -55) || (degree2 == -130) || ...
                                            (degree2 == 10) || (degree2 == 85) || ...
                                            (degree2 == 160))
                                            writePosition(s1, 0);
                                            pause(2);
                                        else
                                            writePosition(s1, 0.4);
                                            pause(2);
                                        end

                                        %Moves arm down to pick up washer
                                        writePosition(s2, 0.95);
                                        pause(2);
                                        
                                        %Move arm up
                                        writePosition(s2, 0.99);
                                        pause(2);
                                        
                                        %Go to filled spot
                                        emptyDegree = initialTable{c3}{1};
                                      tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                      pause(2);
                                      
                                      degree2 = emptyDegree;
                                      %Moves arm to the board
                                      if ((degree2 == -55) || (degree2 == -130) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 160))

                                        writePosition(s1, 0);
                                        pause(2);
                                      else
                                        writePosition(s1, 0.4);
                                        pause(2);
                                      end
                                      
                                      %Move arm down
                                      writePosition(s2, 0.95);
                                      pause(2);
                                      
                                      %Move arm up
                                      writePosition(s2, 0.99);
                                      pause(2);

                                      %Delete the position of washer in initial
                                      %Table
                                      initialTable{c3}{2} = '';
                                      
                                      %Reset value of boolean variable
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
    
    %Reset position of arm in the y-axis
    writePosition(s2, .99);
    pause(2);
    
    %Resets position of arm in the x-axis
    writePosition(s1, 1);
    pause(2);
    
    %Clears ARDUINO UNO
    clear a s1 s2;
    pause(2);
    
    %Moves gameboard to origin position
    tg.setparam(tg.getparamid('Degree', 'Value'), 0);
    pause(2);
end