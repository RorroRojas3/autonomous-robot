function [sortedCell] = sortDegreesAndColors(wellLocation, colors, degrees)
    
    %Cell with corresponding degrees
    sortedCell = {{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''},{'', '', ''}};
    degreeArray = [-27.5, -60.5, -92.5, -120, -156, 13.50, 43.5, 87.5, 135, 163];
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