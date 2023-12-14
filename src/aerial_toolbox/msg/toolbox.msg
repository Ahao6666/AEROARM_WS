time stamp              #时间戳，单位毫秒  
uint8 tool_id           #工具ID，具体的编号，在箱子上标注  
float64[3] position     #工具圆心在机体坐标下的位置  
float64[4] orientation  #工具圆心在机体坐标下的旋转，四元数，顺序wxyz  
float64[3] z_vec        #工具z轴向量在机体坐标下的坐标  
uint8 detected_num      #当前检测到tag的数目  
