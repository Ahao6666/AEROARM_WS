# Aerial toolbox 
msg目录下是发布消息格式  
toolbox_array是不同工具的坐标数组。  
toolbox是每个工具的坐标。  
具体含义如下  
int64 stamp  //时间戳，单位毫秒  
uint8 tool_id //工具ID，具体的编号，在箱子上标注  
float64[3] position //工具圆心在机体坐标下的位置  
float64[4] orientation //工具圆心在机体坐标下的旋转，四元数，顺序wxyz  
float64[3] z_vec //工具z轴向量在机体坐标下的坐标  
uint8 detected_num //当前检测到tag的数目  



订阅该自定义消息，引用   
aerial_toolbox/toolbox_array.h  
aerial_toolbox/toolbox.h  
消息名：/tool_box_pos   
消息类型：aerial_toolbox::toolbox_array  
