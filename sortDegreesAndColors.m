function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    %Cell with corresponding degrees
    sortedCell = {{-13, ''},{-40, ''},{-88, ''},{-130, ''},{-162, ''},{30, ''},{65, ''},{95, ''},{125, ''},{160, ''}};
              
    %Determines washer detected in their corresponding degree and adds it
    %to cell array
    for c1 = 1:10
        for c2 = 1:numel(degrees)
                
            min = wellLocation(c1) - 10;
            max = wellLocation(c1) + 10;
            if ((degrees(c2) > min) && (degrees(c2) < max))
                sortedCell{c1}{2} = colors(c2);
            end

            min = 0;
            max = 0;
        end
    end
end