function sortWashers(initialTable, finalTable, tg)

    % Sets up the Arm to initial position
    [a, s1, s2] = arduinoSetup();
    degreeArray = [-25, -57, -90, -120, -155, 10, 45, 85, 135, 163];
    terminate = 0;
    for c1 = 1:10
        emptySpot = 0;
        finalColor = finalTable{c1, 2};
        
        %Checks if the user input a color in certain degree
        if (terminate == 0)
            if ((strcmp(finalColor, '') == 0))
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
                        degree = initialTable{c2}{1};
                        
                        %Rotates motor to the corresponding degree
                        tg.setparam(tg.getparamid('Degree','Value'), degree);
                        pause(.5);
                        
                        %Checks distance that arm must travel in the x-axis
                        %based on the degree value
                        degree2 = initialTable{c2}{1};
                        if ((degree2 == -57) || (degree2 == -120) || ...
                            (degree2 == 10) || (degree2 == 85) || ...
                            (degree2 == 163))
                            writePosition(s1, 0);
                            pause(1);
                        else
                            writePosition(s1, 0.35);
                            pause(1);
                        end
                        
                        tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                        pause(.5);
                        
                        %Moves arm down to pick up washer
                        writePosition(s2, 0.65);
                        pause(.5);
                                
                        %Moves arm to initial position
                        writePosition(s2, .99);
                        pause(.5);

                        %Dummy asked user for weightPicked
                        %weightPicked = input('Enter weight: ');
                        pause(2);
                        loadCell = tg.getsignal('Load Cell');
                        loadCell = loadCell * 100;
                        fprintf('%f\n', loadCell);
                        
                        %Checks the level of weight input by the user and
                        %the washer weight that has been picked up by the
                        %electro magnet
                        if ((loadCell > -97) && (loadCell < -92) && (washerWeight == 1))
                              
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

                                  fprintf('Here1\n');
                                  %Obtains degree value of empty hole
                                  emptyDegree = initialTable{c3}{1};
                                  
                                  %Go to empty hole
                                  tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                  pause(.5);
                                
                                  %Checks distance that arm must travel in the x-axis
                                  %based on the degree value
                                  degree2 = emptyDegree;
                                  if ((degree2 == -57) || (degree2 == -120) || ...
                            (degree2 == 10) || (degree2 == 85) || ...
                            (degree2 == 163))
                                      writePosition(s1, 0);
                                      pause(1);
                                  else
                                      writePosition(s1, 0.35);
                                      pause(1);
                                  end
                                  
                                  tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                  pause(1);
                                  
                                  %Drop the washer
                                  writePosition(s2, 0.65);
                                  pause(1);
                                  
                                  
                                    
                                  %Move up arm
                                  writePosition(s2, .99);
                                  pause(.5);
                                  
                                  %Delete position of washer in the initial
                                  %Table
                                  initialTable{c2}{2} = '';
                                  initialTable{c3}{2} = finalTable{c1, 2};
                                  finalTable{c1, 2} = '';
                                  finalTable{c1, 3} = '';
                                  break;
                                  
                              %Degree which washer will be moved is not
                              %empty
                              else
                                fprintf('Here2\n');
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                pause(1);
                                
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(1);
                                
                                %Move arm up
                                writePosition(s2, 0.99);
                                pause(.5);
                                
                                %Looks for empty spot on initial table  
                                for c4 = 1:10
                                    if (strcmp(initialTable{c4}{2}, '') == 1)
                                        emptySpot = 1;
                                        emptyDegree = initialTable{c4}{1};
                                        break;
                                    end
                                end
                                
                                if (emptySpot == 1)
                                    
                                    %Looks for color in the spot wanted
                                    for c5 = 1:10
                                        if (degreeArray(c5) == nextDegree)
                                            colorOnWantedSpot = initialTable{c5}{2};
                                            break;
                                        end
                                    end
                                    
                                    %Go to filled spot
                                    tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                    pause(.5);
                                    
                                    %Turn Magnet on
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Move arm down 
                                    writePosition(s2, 0.65);
                                    pause(.5);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to empty spot
                                    tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c4}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
        
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(1);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to initial washer
                                    tg.setparam(tg.getparamid('Degree','Value'), degree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c2}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Turn MAgnet On
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(1);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to desired position
                                    tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(1);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Erase data from table
                                    initialTable{c2}{2} = '';
                                    initialTable{c4}{2} = colorOnWantedSpot;
                                    initialTable{c5}{2} = 'Moved';
                                    finalTable{c1, 2} = '';
                                    finalTable{c1, 3} = '';
                                    break;
                                else
                                    terminate = 1;
                                    break;
                                end

                              end
                                 
                         elseif ((loadCell > -89) && (loadCell  < -84) && (washerWeight == 2))
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

                                  fprintf('Here1\n');
                                  %Obtains degree value of empty hole
                                  emptyDegree = initialTable{c3}{1};
                                  
                                  %Go to empty hole
                                  tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                  pause(.5);
                                
                                  %Checks distance that arm must travel in the x-axis
                                  %based on the degree value
                                  degree2 = emptyDegree;
                                  if ((degree2 == -57) || (degree2 == -120) || ...
                            (degree2 == 10) || (degree2 == 85) || ...
                            (degree2 == 163))
                                      writePosition(s1, 0);
                                      pause(1);
                                  else
                                      writePosition(s1, 0.35);
                                      pause(1);
                                  end
                                  
                                  tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                  pause(1);
                                  
                                  %Drop the washer
                                  writePosition(s2, 0.65);
                                  pause(1);
                                  
                                  
                                    
                                  %Move up arm
                                  writePosition(s2, .99);
                                  pause(.5);
                                  
                                  %Delete position of washer in the initial
                                  %Table
                                  initialTable{c2}{2} = '';
                                  initialTable{c3}{2} = finalTable{c1, 2};
                                  finalTable{c1, 2} = '';
                                  finalTable{c1, 3} = '';
                                  break;
                                  
                              %Degree which washer will be moved is not
                              %empty
                              else
                                fprintf('Here2\n');
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                pause(1);
                                
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(1);
                                
                                %Move arm up
                                writePosition(s2, 0.99);
                                pause(.5);
                                
                                %Looks for empty spot on initial table  
                                for c4 = 1:10
                                    if (strcmp(initialTable{c4}{2}, '') == 1)
                                        emptySpot = 1;
                                        emptyDegree = initialTable{c4}{1};
                                        break;
                                    end
                                end
                                
                                if (emptySpot == 1)
                                    
                                    %Looks for color in the spot wanted
                                    for c5 = 1:10
                                        if (degreeArray(c5) == nextDegree)
                                            colorOnWantedSpot = initialTable{c5}{2};
                                            break;
                                        end
                                    end
                                    
                                    %Go to filled spot
                                    tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                    pause(.5);
                                    
                                    %Turn Magnet on
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Move arm down 
                                    writePosition(s2, 0.65);
                                    pause(.5);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to empty spot
                                    tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c4}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
        
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(1);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to initial washer
                                    tg.setparam(tg.getparamid('Degree','Value'), degree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c2}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Turn MAgnet On
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(1);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to desired position
                                    tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(1);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Erase data from table
                                    initialTable{c2}{2} = '';
                                    initialTable{c4}{2} = colorOnWantedSpot;
                                    initialTable{c5}{2} = 'Moved';
                                    finalTable{c1, 2} = '';
                                    finalTable{c1, 3} = '';
                                    break;
                                else
                                    terminate = 1;
                                    break;
                                end

                              end
                         elseif ((loadCell > -83.8) && (washerWeight == 3))
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

                                  fprintf('Here1\n');
                                  %Obtains degree value of empty hole
                                  emptyDegree = initialTable{c3}{1};
                                  
                                  %Go to empty hole
                                  tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                  pause(.5);
                                
                                  %Checks distance that arm must travel in the x-axis
                                  %based on the degree value
                                  degree2 = emptyDegree;
                                  if ((degree2 == -57) || (degree2 == -120) || ...
                            (degree2 == 10) || (degree2 == 85) || ...
                            (degree2 == 163))
                                      writePosition(s1, 0);
                                      pause(1);
                                  else
                                      writePosition(s1, 0.35);
                                      pause(1);
                                  end
                                  
                                  tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                  pause(1);
                                  
                                  %Drop the washer
                                  writePosition(s2, 0.65);
                                  pause(2);
                                  
                                  
                                    
                                  %Move up arm
                                  writePosition(s2, .99);
                                  pause(.5);
                                  
                                  %Delete position of washer in the initial
                                  %Table
                                  initialTable{c2}{2} = '';
                                  initialTable{c3}{2} = finalTable{c1, 2};
                                  finalTable{c1, 2} = '';
                                  finalTable{c1, 3} = '';
                                  break;
                                  
                              %Degree which washer will be moved is not
                              %empty
                              else
                                fprintf('Here2\n');
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                pause(1);
                                
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(2);
                                
                                %Move arm up
                                writePosition(s2, 0.99);
                                pause(.5);
                                
                                %Looks for empty spot on initial table  
                                for c4 = 1:10
                                    if (strcmp(initialTable{c4}{2}, '') == 1)
                                        emptySpot = 1;
                                        emptyDegree = initialTable{c4}{1};
                                        break;
                                    end
                                end
                                
                                if (emptySpot == 1)
                                    
                                    %Looks for color in the spot wanted
                                    for c5 = 1:10
                                        if (degreeArray(c5) == nextDegree)
                                            colorOnWantedSpot = initialTable{c5}{2};
                                            break;
                                        end
                                    end
                                    
                                    %Go to filled spot
                                    tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                    pause(.5);
                                    
                                    %Turn Magnet on
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Move arm down 
                                    writePosition(s2, 0.65);
                                    pause(2);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to empty spot
                                    tg.setparam(tg.getparamid('Degree','Value'), emptyDegree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c4}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
        
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(2);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to initial washer
                                    tg.setparam(tg.getparamid('Degree','Value'), degree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c2}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Turn MAgnet On
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 1);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(2);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Go to desired position
                                    tg.setparam(tg.getparamid('Degree','Value'), nextDegree);
                                    pause(.5);
                                    
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -57) || (degree2 == -120) || ...
                                        (degree2 == 10) || (degree2 == 85) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                    
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                                    pause(1);
                                    
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(2);
                                    
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                    
                                    %Erase data from table
                                    initialTable{c2}{2} = '';
                                    initialTable{c4}{2} = colorOnWantedSpot;
                                    initialTable{c5}{2} = 'Moved';
                                    finalTable{c1, 2} = '';
                                    finalTable{c1, 3} = '';
                                    break;
                                else
                                    terminate = 1;
                                    break;
                                end

                              end
                        else
                            %Turn Magnet off
                            tg.setparam(tg.getparamid('magnetOn','Value'), 0);
                            pause(1);

                            %Move arm down
                            writePosition(s2, 0.65);
                            pause(2);

                            %Move arm up
                            writePosition(s2, 0.99);
                            pause(.5);
                        end
                     end
                 end
             end
         end
       else
            fprintf('No empty spots\n');
            fprintf('Program will be terminated\n');
            break;
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
    pause(.5);
end