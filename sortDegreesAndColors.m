function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    %Cell with corresponding degrees
    sortedCell = {{-20, ''},{-50, ''},{-90, ''},{-130, ''},{-160, ''},{20, ''},{55, ''},{90, ''},{125, ''},{150, ''}};
              
    %Determines washer detected in their corresponding degree and adds it
    %to cell array
    for c1 = 1:10
        for c2 = 1:numel(degrees)
                
            min = wellLocation(c1) - 8;
            max = wellLocation(c1) + 8;
            if ((degrees(c2) > min) && (degrees(c2) < max))
                sortedCell{c1}{2} = colors(c2);
            end

            min = 0;
            max = 0;
        end
    end
end