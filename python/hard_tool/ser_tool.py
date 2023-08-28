
class SerTool():

    def __init__(self):
        pass

        # 打印行号
    def logshow(self,frame_info, mess):

        info = frame_info.f_code
        paths =  info.co_filename.split('\\')
        print(f'目录:{paths[-2]} 文件名:{paths[-1]} 函数名:{info.co_name} 行数:{frame_info.f_lineno}\n 输出消息:{mess}')


