function sortWashers2(initialTable, finalTable, tg)
% Sets up the Arm to initial position
[a, s1, s2] = arduinoSetup();
degreeArray = [-27.5, -60.5, -92.5, -120, -156, 13.50, 43.5, 87.5, 135, 163];
terminate = 0;


for c1 = 1:10
    emptySpot = 0;
    finalColor = finalTable{c1, 2};
    average = 0;
    %status = get_param('Q4 DI', 'Shown')
    %Checks if the user input a color in certain degree
    if ((terminate == 0))
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
                        tg.setparam(tg.getparamid('Degree', 'Value'), degree);
                        pause(1.2);
                     
                        %Checks distance that arm must travel in the x-axis
                        %based on the degree value
                        degree2 = initialTable{c2}{1};
                        if ((degree2 == -60.5) || (degree2 == -120) || ...
                            (degree2 == 13.5) || (degree2 == 87.5) || ...
                            (degree2 == 163))
                            writePosition(s1, 0);
                            pause(1);
                        else
                            writePosition(s1, 0.35);
                            pause(1);
                        end
                     
                        %Turn Magnet On
                        tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                        pause(.1);
                     
                        %Moves arm down to pick up washer
                        writePosition(s2, 0.65);
                        pause(3.0);
                     
                        %Moves arm to initial position
                        writePosition(s2, .99);
                        pause(.5);
                        
                        writePosition(s1, 0);
                        pause(.5);
                     
                        %Dummy asked user for weightPicked
                        %weightPicked = input('Enter weight: ');
                        pause(2);
                        for c6 = 1:20
                            loadCell = tg.getsignal('Load Cell');
                            loadCell = loadCell * 100;
                            average = average + loadCell;
                            pause(.01);
                        end
                        average = average / 20;
                        loadCell = average;
                        fprintf('Average: %.2f\n', average);
                        
                        degree2 = initialTable{c2}{1};
                        if ((degree2 == -60.5) || (degree2 == -120) || ...
                            (degree2 == 13.5) || (degree2 == 87.5) || ...
                            (degree2 == 163))
                            writePosition(s1, 0);
                            pause(1);
                        else
                            writePosition(s1, 0.35);
                            pause(1);
                        end
                        
                     
                        %Checks the level of weight input by the user and
                        %the washer weight that has been picked up by the
                        %electro magnet
                        if ((loadCell > 263) && (loadCell <272) && (washerWeight == 1))
                            fprintf('Level 1: %f\n', loadCell);
                            %Degree which the washer will be
                            %moved to
                            nextDegree = degreeArray(c1);
                            originalDegree = initialTable{c2}{1};
                            
                            %Checks if washer is already in the position
                            %desired
                            if (nextDegree == originalDegree)
                                
                                %Turn Magnet Off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                     
                                %Moves arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                     
                                %Moves arm up
                                writePosition(s2, .99);
                                pause(.5);
                                
                                %Updates both initial and final table
                                initialTable{c2}{2} = 'Moved';
                                finalTable{c1, 2} = '';
                                finalTable{c1, 3} = '';
                                break;
                            end
                            
                         
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
                             
                                fprintf('Found empty spot\n');
                             
                                %Obtains degree value of empty hole
                                emptyDegree = initialTable{c3}{1};
                             
                                %Go to empty hole
                                tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                pause(1.2);
                             
                                %Checks distance that arm must travel in the x-axis
                                %based on the degree value
                                degree2 = emptyDegree;
                                if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                    (degree2 == 13.5) || (degree2 == 87.5) || ...
                                    (degree2 == 163))
                                    writePosition(s1, 0);
                                    pause(1);
                                else
                                    writePosition(s1, 0.35);
                                    pause(1);
                                end
                             
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
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
                                initialTable{c3}{2} = 'Moved';
                                finalTable{c1, 2} = '';
                                finalTable{c1, 3} = '';
                                break;
                             
                                %Degree which washer will be moved is not
                                %empty
                            else
                             
                                fprintf('Spot is filled\n')
                             
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                             
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                             
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
                                    tg.setparam(tg.getparamid('Degree', 'Value'), nextDegree);
                                    pause(1.2);
                                 
                                    %Turn Magnet on
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                                    pause(.1);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to empty spot
                                    tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c4}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                    pause(1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to initial washer
                                    tg.setparam(tg.getparamid('Degree', 'Value'), degree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c2}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet On
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                                    pause(.1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to desired position
                                    tg.setparam(tg.getparamid('Degree', 'Value'), nextDegree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                    pause(1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
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
                         
                        elseif ((loadCell > 275) && (loadCell < 279) && (washerWeight == 2))
                            fprintf('Level 2: %f\n', loadCell);
                            %Degree which the washer will be
                            %moved to
                            nextDegree = degreeArray(c1);
                            originalDegree = initialTable{c2}{1};
                            if (nextDegree == originalDegree)
                                
                                %Turn Magnet Off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                     
                                %Moves arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                     
                                %Moves arm up
                                writePosition(s2, .99);
                                pause(.5);
                                
                                %Updates both initial and final table
                                initialTable{c2}{2} = 'Moved';
                                finalTable{c1, 2} = '';
                                finalTable{c1, 3} = '';
                                break;
                            end
                         
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
                             
                                fprintf('Moving Washer new spot\n');
                                
                                %Obtains degree value of empty hole
                                emptyDegree = initialTable{c3}{1};
                             
                                %Go to empty hole
                                tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                pause(1.2);
                             
                                %Checks distance that arm must travel in the x-axis
                                %based on the degree value
                                degree2 = emptyDegree;
                                if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                    (degree2 == 13.5) || (degree2 == 87.5) || ...
                                    (degree2 == 163))
                                    writePosition(s1, 0);
                                    pause(1);
                                else
                                    writePosition(s1, 0.35);
                                    pause(1);
                                end
                             
                                %Turn Magnet Off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
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
                                
                                fprintf('Spot is filled\n');
                                
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                             
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                             
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
                                    tg.setparam(tg.getparamid('Degree', 'Value'), nextDegree);
                                    pause(1.2);
                                 
                                    %Turn Magnet on
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                                    pause(.1);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to empty spot
                                    tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c4}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                    pause(1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to initial washer
                                    tg.setparam(tg.getparamid('Degree', 'Value'), degree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c2}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet On
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                                    pause(.1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to desired position
                                    tg.setparam(tg.getparamid('Degree', 'Value'), nextDegree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                    pause(1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
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
                        elseif ((loadCell >= 279.5) && (washerWeight == 3))
                            fprintf('Level 3: %f\n', loadCell);
                            %Degree which the washer will be
                            %moved to
                            nextDegree = degreeArray(c1);
                            
                            %Original degree of washer
                            originalDegree = initialTable{c2}{1};
                            
                            
                            if (nextDegree == originalDegree)
                                
                                %Turn Magnet Off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                     
                                %Moves arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                     
                                %Moves arm up
                                writePosition(s2, .99);
                                pause(.5);
                                
                                %Updates both initial and final table
                                initialTable{c2}{2} = 'Moved';
                                finalTable{c1, 2} = '';
                                finalTable{c1, 3} = '';
                                break;
                            end
                         
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
                             
                                fprintf('Moving washer to new spot\n');
                                
                                %Obtains degree value of empty hole
                                emptyDegree = initialTable{c3}{1};
                             
                                %Go to empty hole
                                tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                pause(1.2);
                             
                                %Checks distance that arm must travel in the x-axis
                                %based on the degree value
                                degree2 = emptyDegree;
                                if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                    (degree2 == 13.5) || (degree2 == 87.5) || ...
                                    (degree2 == 163))
                                    writePosition(s1, 0);
                                    pause(1);
                                else
                                    writePosition(s1, 0.35);
                                    pause(1);
                                end
                             
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                             
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                             
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
                                
                                fprintf('Spot is filled\n');
                                
                                %Turn Magnet off
                                tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                pause(1);
                             
                                %Move arm down
                                writePosition(s2, 0.65);
                                pause(3.0);
                             
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
                                    tg.setparam(tg.getparamid('Degree', 'Value'), nextDegree);
                                    pause(1.2);
                                 
                                    %Turn Magnet On
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                                    pause(.1);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to empty spot
                                    tg.setparam(tg.getparamid('Degree', 'Value'), emptyDegree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c4}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                    pause(1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to initial washer
                                    tg.setparam(tg.getparamid('Degree', 'Value'), degree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c2}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet On
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 1);
                                    pause(.1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
                                    %Move arm up
                                    writePosition(s2, 0.99);
                                    pause(.5);
                                 
                                    %Go to desired position
                                    tg.setparam(tg.getparamid('Degree', 'Value'), nextDegree);
                                    pause(1.2);
                                 
                                    %Checks distance that arm must travel in the x-axis
                                    %based on the degree value
                                    degree2 = initialTable{c1}{1};
                                    if ((degree2 == -60.5) || (degree2 == - 120) || ...
                                        (degree2 == 13.5) || (degree2 == 87.5) || ...
                                        (degree2 == 163))
                                        writePosition(s1, 0);
                                        pause(1);
                                    else
                                        writePosition(s1, 0.35);
                                        pause(1);
                                    end
                                 
                                    %Turn Magnet off
                                    tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                                    pause(1);
                                 
                                    %Move arm down
                                    writePosition(s2, 0.65);
                                    pause(3.0);
                                 
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
                            tg.setparam(tg.getparamid('magnetOn', 'Value'), 0);
                            pause(1);
                         
                            %Move arm down
                            writePosition(s2, 0.65);
                            pause(3.0);
                         
                            %Move arm up
                            writePosition(s2, 0.99);
                            pause(.5);
                        end
                    end
                end
            end
        end
    else
        fprintf('Error\n');
        fprintf('Program will be terminated\n');
        break;
    end
end

%Reset position of arm in the y-axis
writePosition(s2, .99);
pause(2);

%Resets position of arm in the x-axis
writePosition(s1, 1);
pause(1);

%Clears ARDUINO UNO
clear a s1 s2;
pause(1);

%if (status == 0)
    %Moves gameboard to origin position
    tg.setparam(tg.getparamid('Degree', 'Value'), 0);
    pause(3.0);
%end

end