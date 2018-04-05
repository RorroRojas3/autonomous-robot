function [washer] = getAllWashers(snapShot, properties)

    c2 = 1;
    %true = 0;
    for c1 = 1:numel(properties)
        radius = sqrt(properties(c1).Area / pi);
        halfRadius = radius / 2;

        % Obtains Average Red value of current Washer
        color1 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 1)));
        color2 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 1)));
        color3 = sum(sum(snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 1)));
        color4 = sum(sum(snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 1)));
        color5 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 3, floor(properties(c1).Centroid(1)) - 8, 1)));
        color6 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 3, floor(properties(c1).Centroid(1)) + 8, 1)));
        color7 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius) - 3, floor(properties(c1).Centroid(1)) - 8, 1)));
        color8 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius) - 3, floor(properties(c1).Centroid(1)) + 8, 1)));
        redColor  = color1 + color2 + color3 + color4 + color5 + color6 + color7 + color8;

        % Obtains Average Green value of current Washer
        color1 = 0;
        color2 = 0;
        color3 = 0;
        color4 = 0;
        color5 = 0;
        color6 = 0;
        color7 = 0;
        color8=  0;
        color1 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 2)));
        color2 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 2)));
        color3 = sum(sum(snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 2)));
        color4 = sum(sum(snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 2)));
        color5 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 3, floor(properties(c1).Centroid(1)) - 8, 2)));
        color6 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 3, floor(properties(c1).Centroid(1)) + 8, 2)));
        color7 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius) - 3, floor(properties(c1).Centroid(1)) - 8, 2)));
        color8 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius) - 3, floor(properties(c1).Centroid(1)) + 8, 2)));
        greenColor = color1 + color2 + color3 + color4 + color5 + color6 + color7 + color8;

        % Obtains Average Blue value of current Washer
        color1 = 0;
        color2 = 0;
        color3 = 0;
        color4 = 0;
        color5 = 0;
        color6 = 0;
        color7 = 0;
        color8=  0;
        color1 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius), floor(properties(c1).Centroid(1)), 3)));
        color2 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius), floor(properties(c1).Centroid(1)), 3)));
        color3 = sum(sum(snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) - halfRadius), 3)));
        color4 = sum(sum(snapShot(floor(properties(c1).Centroid(2)), floor(properties(c1).Centroid(1) + halfRadius), 3)));
        color5 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 3, floor(properties(c1).Centroid(1)) - 8, 3)));
        color6 = sum(sum(snapShot(floor(properties(c1).Centroid(2) - halfRadius) + 3, floor(properties(c1).Centroid(1)) + 8, 3)));
        color7 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius) - 3, floor(properties(c1).Centroid(1)) - 8, 3)));
        color8 = sum(sum(snapShot(floor(properties(c1).Centroid(2) + halfRadius) - 3, floor(properties(c1).Centroid(1)) + 8, 3)));
        blueColor = color1 + color2 + color3 + color4 + color5 + color6 + color7 + color8;

        if ((redColor > greenColor) && (redColor > blueColor))
            fprintf("Washer #%d is RED\n", c1);
            washer(c2) = "Red";
            %true = 1;
            c2 = c2 + 1;
        elseif ((greenColor > redColor) && (greenColor > blueColor))
            fprintf('Washer #%d is GREEN\n', c1);
            washer(c2) = "Green";
            %true = 1;
            c2 = c2 + 1;
        elseif ((blueColor > redColor) && (blueColor > greenColor))
            fprintf('Washer #%d is BLUE\n', c1);
            washer(c2) = "Blue";
            %true = 1;
            c2 = c2 + 1;
        end
    end
    
%     if (true == 0)
%         washer = 0;
%     end
    
end