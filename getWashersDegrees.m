function degrees = getWashersDegrees(properties)
    for c1= 1:numel(properties)
        centerX = 320;
        centerY = 240;
        currentX = properties(c1).Centroid(1);
        currentY = properties(c1).Centroid(2);

        if (currentX > centerX)
            x(c1) = abs(centerX - currentX);
        else
            x(c1) =  currentX - centerX;
        end

        if (currentY < centerY)
            y(c1) = abs(centerY - currentY);
        else
            y(c1) = centerY - currentY;
        end

        if ((y(c1) >= 0) && (x(c1) <= 0))
            degrees(c1) = -180 + atand(abs(y(c1) / x(c1)));
        elseif ((y(c1) >= 0) && (x(c1) >= 0))
            degrees(c1) = -1 * atand(abs(y(c1) / x(c1))); 
        elseif ((y(c1) <= 0) && (x(c1) >= 0))
            degrees(c1) = atand(abs(y(c1) / x(c1)));
        else
            degrees(c1) = 180 - atand(abs(y(c1) / x(c1)));
        end

        
        fprintf('Washer #%d | Degree: %.3f\n', c1, degrees(c1));
    end
    fprintf('\nDegrees have been obtained\n');
end