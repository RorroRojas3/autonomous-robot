function background = getBackgroundImage(cam)
  
    true = 1;
    while (true == 1)
        command = input('Take Background Picture? [Y/N]: ', 's');
        if (strcmp('Y', command) == 1)
            background = snapshot(cam);
            true = 0;
        end
    end
    
end
