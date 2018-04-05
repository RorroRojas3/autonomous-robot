function sortWashers(initial, final)
    
    for c1 = 1:numel(final)
        color = final{c1, 2};
        if ((strcmp(color, '')) == 0)
            for c2 = 1:numel(initial)
                color2 = initial{c2}{2};
                if ((strcmp(color, color2)) == 1)
                    weight = final(c1, 3);
                    weight = str2double(weight);
                    if ((strcmp(weight, '')) == 0)
                        fprintf('Here\n');
                        %Calculate weight of picked up washer
                        %weightPicked = loadCellFunction
                        if ((weightPicked < 10) && (weight < 10))
                            %Level one picked up and moved
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
end