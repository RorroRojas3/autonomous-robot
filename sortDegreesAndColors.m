function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    %Cell with corresponding degrees
    sortedCell = {{-25, '', ''},{-55, '', ''},{-88, '', ''},{-130, '', ''},{-162, '', ''},{10, '', ''},{40, '', ''},{85, '', ''},{130, '', ''},{160, '', ''}};
              
    %Determines washer detected in their corresponding degree and adds it
    %to cell array
    for c1 = 1:10
        for c2 = 1:numel(degrees)
                
            min = wellLocation(c1) - 20;
            max = wellLocation(c1) + 20;
            if ((degrees(c2) > min) && (degrees(c2) < max))
                sortedCell{c1}{2} = colors(c2);
                sortedCell{c1}{3} = degrees(c2);
                fprintf('%d\n', sortedCell{c1}{3});
                fprintf('%d\n', c1);
            end

            min = 0;
            max = 0;
        end
    end
end