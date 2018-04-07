function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    sortedCell = {{-30, ''},{-65, ''},{-95, ''},{-125, ''},{-160, ''},{10, ''},{40, ''},{85, ''},{130, ''},{160, ''}};
              

    for c1 = 1:10
        for c2 = 1:numel(degrees)
            if (wellLocation <= 5)
                min = wellLocation(c1) - 6;
                max = wellLocation(c1) + 6;
                if ((degrees(c2) > min) && (degrees(c2) < max))
                    sortedCell{c1}{2} = colors(c2);
                end
            else
                min = wellLocation(c1) - 6;
                max = wellLocation(c1) + 6;
                if ((degrees(c2) > min) && (degrees(c2) < max))
                    sortedCell{c1}{2} = colors(c2);
                end
            end
        end
    end
   
end