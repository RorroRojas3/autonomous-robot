function snapShot = getSnapshotImage(cam)

    true = 1;
    while (true == 1)
        command2 = input('Take Snapshot Picture? [Y/N]: ', 's');
        if (strcmp('Y', command2) == 1)
            snapShot = snapshot(cam);
            true = 0;
        end
    end
    
end