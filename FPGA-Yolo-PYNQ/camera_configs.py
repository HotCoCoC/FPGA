import cv2
import numpy as np
 
#右摄像头参数
right_camera_matrix = np.array([[970.442193175645, 0.662149120351574,447.385660951263],
                               [0, 999.526759034729,319.300319578679],
                               [0, 0, 1]])
right_distortion = np.array([[-0.393721056519224,-1.02362248626099,-0.0224780874816298,-0.0215989661904819,4.08552046615739]])
 
#左摄像头参数
left_camera_matrix = np.array([[973.453231048070, 5.89303592282359, 445.920724405380],
                                [0, 995.574759198988, 317.679734843106],
                                [0, 0, 1]])
left_distortion = np.array([[-0.448699357794973,-0.0849339675189154,-0.0225275384276436,-0.0207099739316165, 0.196909016690212]])
 
#om = np.array([0.00456, 0.01463, 0.00042])        # 旋转关系向量
R = np.array([[0.999950836750182,-0.00214232390047800,-0.00968165951255393],
                                [0.00222247923459049,0.999963284118255,0.00827592904065060],
                                [0.00966357432130572,-0.00829703945630673,0.999918883943891]])                         # 使用Rodrigues变换将om变换为R
T = np.array([-57.5773465003307, 0.275555865411103,-9.17672718122313])      # 平移关系向量
 
size = (640, 480) # 图像尺寸
 
# 进行立体更正
R1, R2, P1, P2, Q, validPixROI1, validPixROI2 = cv2.stereoRectify(left_camera_matrix, left_distortion,
                                                                  right_camera_matrix, right_distortion, size, R,
                                                                  T)
# 计算更正map
left_map1, left_map2 = cv2.initUndistortRectifyMap(left_camera_matrix, left_distortion, R1, P1, size, cv2.CV_16SC2)
right_map1, right_map2 = cv2.initUndistortRectifyMap(right_camera_matrix, right_distortion, R2, P2, size, cv2.CV_16SC2)