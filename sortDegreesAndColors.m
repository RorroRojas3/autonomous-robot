function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    %Cell with corresponding degrees
    sortedCell = {{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''}};
    degreeArray = [-25, -57, -90, -120, -155, 10, 45, 85, 135, 163];
    %Determines washer detected in their corresponding degree and adds it
    %to cell array
    for c1 = 1:10
        sortedCell{c1}{1} = degreeArray(c1);
        for c2 = 1:numel(degrees)
            min = wellLocation(c1) - 20;
            max = wellLocation(c1) + 20;
            if ((degrees(c2) > min) && (degrees(c2) < max))
                sortedCell{c1}{2} = colors(c2);
                sortedCell{c1}{3} = degrees(c2);
            end

            min = 0;
            max = 0;
        end
    end
end