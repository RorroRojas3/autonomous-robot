function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    sortedCell = {{-20, ''},{-65, ''},{-95, ''},{-125, ''},{-160, ''},{10, ''},{55, ''},{85, ''},{125, ''},{150, ''}};
              

    for c1 = 1:10
        
        for c2 = 1:numel(degrees)
%             if (wellLocation <= 5)
                min = wellLocation(c1) - 8;
                max = wellLocation(c1) + 8;

                %fprintf('%d\n', min);
                
                %fprintf('%d\n', max);
                if ((degrees(c2) > min) && (degrees(c2) < max))
                    sortedCell{c1}{2} = colors(c2);
                end
                min = 0;
                max = 0;
%             else
%                 min = wellLocation(c1) - 8;
%                 max = wellLocation(c1) + 8;
%                 fprintf('%.2f\n', min);
%                 fprintf('%.2f\n', max);
%                 if ((degrees(c2) > min) && (degrees(c2) < max))
%                     sortedCell{c1}{2} = colors(c2);
%                 end
%             end
        end
    end
   
end