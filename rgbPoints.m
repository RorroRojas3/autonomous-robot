function rgbPoints(snapShot, properties)

    figure, imshow(snapShot);
    hold on;
    for c1 = 1:numel(properties)
       radius = sqrt(properties(c1).Area / pi);
       halfRadius = radius / 2;
       plot(floor(properties(c1).Centroid(1) - halfRadius), floor(properties(c1).Centroid(2)), 'rx'); 
       plot(floor(properties(c1).Centroid(1) + halfRadius), floor(properties(c1).Centroid(2)), 'rx');
       plot(floor(properties(c1).Centroid(1)), floor(properties(c1).Centroid(2) - halfRadius), 'rx');
       plot(floor(properties(c1).Centroid(1)), floor(properties(c1).Centroid(2) + halfRadius), 'rx');
       plot(floor(properties(c1).Centroid(1) - halfRadius) + 3, floor(properties(c1).Centroid(2)) - 8, 'rx');
       plot(floor(properties(c1).Centroid(1) - halfRadius) + 3, floor(properties(c1).Centroid(2)) + 8, 'rx');
       plot(floor(properties(c1).Centroid(1) + halfRadius) - 3, floor(properties(c1).Centroid(2)) - 8, 'rx');
       plot(floor(properties(c1).Centroid(1) + halfRadius) - 3, floor(properties(c1).Centroid(2)) + 8, 'rx');
    end
    plot(640/2, 480/2, 'rx');
    hold off;

end