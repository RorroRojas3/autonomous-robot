function centroidNumber(snapShot, properties)
   
    imshow(snapShot);
    hold on;
    for c1 = 1: numel(properties)
        text(properties(c1).Centroid(1), properties(c1).Centroid(2), sprintf('%d', c1), ...
        'HorizontalAlignment', 'center', ...
        'VerticalAlignment', 'middle');
    end
    hold off;

end