clear all;
clc;
cam = webcam('HP USB Webcam');
preview(cam);
background = snapshot(cam);
figure, imshow(background);
while (1)
    command = input('Take Picture? [Y/N] ', 's');
    if (strcmp('Y', command) == 1)
        screenShot = snapshot(cam);
        figure, imshow(screenShot);
        difference = im2bw((background - screenShot), 0.03);
        figure, imshow(difference);
        disk = strel('disk', 8);
        erode = imerode(difference, disk);
        figure, imshow(erode);
        disk2 = strel('disk', 10);
        dilute = imdilate(erode, disk2);
        figure, imshow(dilute);
    end
    
end