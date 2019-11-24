#!/usr/bin/python3.5  
# -*- coding: utf-8 -*-  

import cv2
import numpy as np
import camera_configs
 
cv2.namedWindow("depth")
cv2.moveWindow("left", 0, 0)
cv2.moveWindow("right", 640, 0)
cv2.createTrackbar("num", "depth", 2, 10, lambda x: None)
cv2.createTrackbar("blockSize", "depth", 5, 255, lambda x: None)
 
def mask_depth(image,th,throld = 1000):
    global nr
    global nc
   # nr = image.shape[0]
   # nc = image.shape[1]
    nr = len(image)
    nc = len(image[0])
    for i in range(nr):
        for j in range(nc):
            if image[i,j]>throld or image[i,j]<50:
               th[i,j] = 0
def print_location(image):
    global nr
    global nc
   # nr = image.shape[0]
   # nc = image.shape[1]
   # flag[:,:]
    nr = len(image)
    nc = len(image[0])
    font=cv2.FONT_HERSHEY_SIMPLEX
    for i in range(16,int(nr/10)-2):
        for j in range(2,int((nc-1)/10)-2):
            if (image[i*10,j*10]-image[i*10,(j+2)*10])<10 and image[i*10,j*10]> 10 and (image[i*10,j*10] - image[(i-2)*10,j*10]) < 10 and  (image[i*10,j*10]-image[i*10,(j-2)*10])>100 and (image[i*10,j*10] - image[(i+2)*10,j*10]) > 100:
                print(threeD[i*10][j*10])
                cv2.putText(img1_rectified,str(threeD[i*10][j*10][2]),(i*10,j*10), font, 0.5,(255,0,0),2)
    print("\n")
               

# 添加点击事件，打印当前点的距离q
def callbackFunc(e, x, y, f, p):
    if e == cv2.EVENT_LBUTTONDOWN:        
        print (threeD[y][x])
 
cv2.setMouseCallback("depth", callbackFunc, None)
 
cap = cv2.VideoCapture(0+ cv2.CAP_DSHOW)
# ret = cap.set(3, 320)
# ret = cap.set(4, 240)
# 设置摄像头分辨率
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)   
 
while True:
    ret1, frame = cap.read()
    #ret2, frame2 = camera2.read()
    #if not ret1 or not ret2:
    if ret1 != True:
        break
    cv2.resize(frame,(1280,480),interpolation=cv2.INTER_LINEAR)  
    dsize = (1280, 480)
    imagedst = cv2.resize(frame,dsize,interpolation=cv2.INTER_LINEAR)
    
    frame1 = imagedst[0:480,0:640]
    frame2 = imagedst[0:480,640:1280]
 
    # 根据更正map对图片进行重构
    img1_rectified = cv2.remap(frame1, camera_configs.left_map1, camera_configs.left_map2, cv2.INTER_LINEAR)
    img2_rectified = cv2.remap(frame2, camera_configs.right_map1, camera_configs.right_map2, cv2.INTER_LINEAR)
 
    # 将图片置为灰度图，为StereoBM作准备
    imgL = cv2.cvtColor(img1_rectified, cv2.COLOR_BGR2GRAY)
    imgR = cv2.cvtColor(img2_rectified, cv2.COLOR_BGR2GRAY)
#    ret, imgL = cv2.threshold(img1_rectified,127,255,cv2.THRESH_BINARY) #二值化
#    ret, imgR = cv2.threshold(img2_rectified,127,255,cv2.THRESH_BINARY) #二值化
    # 两个trackbar用来调节不同的参数查看效果
    num = cv2.getTrackbarPos("num", "depth")
    blockSize = cv2.getTrackbarPos("blockSize", "depth")
    if blockSize % 2 == 0:
         blockSize += 1
    if blockSize < 5:
         blockSize = 5

    window_size = 5
    min_disp = 0
    num_disp = 320 - min_disp 
     # 根据Block Maching方法生成差异图（opencv里也提供了SGBM/Semi-Global Block Matching算法，有兴趣可以试试）
    
    stereo = cv2.StereoSGBM_create(
    minDisparity=0,
    numDisparities=10*16,  # max_disp has to be dividable by 16 f. E. HH 192, 256
    blockSize=7,
    P1=8 * 3 * window_size ** 2,
    # wsize default 3; 5; 7 for SGBM reduced size image; 15 for SGBM full size image (1300px and above); 5 Works nicely
    P2=32 * 3 * window_size ** 2,
    disp12MaxDiff=10,
    uniquenessRatio=10,
    speckleWindowSize=70,
    speckleRange=2,
    preFilterCap=63,
    mode=cv2.STEREO_SGBM_MODE_SGBM_3WAY
)


    
    disparity = stereo.compute(imgL, imgR)
   # disparity = stereo.compute(imgL, imgR).astype(np.float32) / 16.0
    disp = cv2.normalize(disparity, disparity, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX, dtype=cv2.CV_8U)
    # 将图片扩展至3d空间中，其z方向的值则为当前的距离
    threeD = cv2.reprojectImageTo3D(disparity.astype(np.float32)/16., camera_configs.Q)
    
#    ret, binary = cv2.threshold(disp,0,255,cv2.THRESH_BINARY) #二值化
#    kernel = np.ones((10,10),np.uint8)
#   dilation = cv2.dilate(binary,kernel,iterations = 1)#膨胀


    dep = disp.copy()
    mask_depth(disp,dep,230)
   # print(dep)
    #kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(15,15))
    #opening = cv2.morphologyEx(dep,cv2.MORPH_OPEN,kernel)

    
    #out = np.uint8(opening)  
    #ret, binary = cv2.threshold(out,127,255,cv2.THRESH_BINARY) 
    #contours, hierarchy = cv2.findContours(binary,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE) 
    
   # x,y,w,h=cv2.boundingRect(binary2) 
   # cv2.rectangle(dep, (x, y), (x+w, y+h), (255, 255, 255),3)
  #  print(w,y,w,h,'\n')
    ret, binary2 = cv2.threshold(dep,0,255,cv2.THRESH_BINARY)
    contours, hierarchy = cv2.findContours(binary2,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    for i, contour in enumerate(contours):
#        print(contour)
        x, y, w, h = cv2.boundingRect(contour)
        if(w*h>4000):
 #           print("长宽高",x,y,w,h)
            print(threeD[y+int(h/2)][x+int(w/2)])

    print('\n')
        #img = dst[y-1:y+h+1,x-1:x+w+1]
    #cv2.drawContours(imgL,contours,-1,(0,0,0),3) 
#    cv2.drawContours(opening,hull,-1,(0,0,255),3)

    #min_area = 1400
    #hull=[]
    #def convexHull(contours):
    #    for i in range(len(contours)):
    #       area = cv2.contourArea(contours[i])
    #       if area>=min_area:
           
    #           hull.append(cv2.convexHull(contours[i]))
    #    return hull
    #convexHull(contours)
    #cv2.drawContours(opening,hull,-1,(0,0,255),3)
    print_location(dep)

    cv2.imshow("left", img1_rectified)
    cv2.imshow("right", img2_rectified)
    cv2.imshow("depth", disp)
    cv2.imshow("dep",dep)
 #   cv2.imshow("dep",binary)
 #   cv2.imshow("opening",opening)

#    cv2.imshow("depth1", dilation)
#    cv2.imshow("imgL",binary2)

    key = cv2.waitKey(1)
    #if key == ord("q"):
    #    break
    #elif key == ord("s"):
    #    cv2.imwrite(path_BM_left, imgL)
    #    cv2.imwrite(path_BM_right, imgR)
    #    cv2.imwrite(path_BM_depth, disp)
cap.release()
cv2.destroyAllWindows()