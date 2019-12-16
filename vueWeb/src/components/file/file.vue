<template>
<div>
    <div class="texta">
      <h3>将进酒</h3>
      君不见，黄河之水天上来，奔流到海不复回。<br>
      君不见，高堂明镜悲白发，朝如青丝暮成雪。<br>
      人生得意须尽欢，莫使金樽空对月。<br>
      天生我材必有用，千金散尽还复来。<br>
      烹羊宰牛且为乐，会须一饮三百杯。<br>
      岑夫子，丹丘生，将进酒，杯莫停。<br>
      与君歌一曲，请君为我倾耳听。<br>
      钟鼓馔玉不足贵，但愿长醉不复醒。<br>
      古来圣贤皆寂寞，惟有饮者留其名。<br>
      陈王昔时宴平乐，斗酒十千恣欢谑。<br>
      主人何为言少钱，径须沽取对君酌。<br>
      五花马，千金裘，呼儿将出换美酒，与尔同销万古愁。<br>
      <br>
    </div>
  <div class="upload-a" style="width: 200px;" >
    <el-upload
      ref="upload"
      action=""
      :on-success="uploadSuccess"
      :before-upload="beforeUpload"
      :fileList="fileList"
      :limit="9"
      list-type="picture"
      :auto-upload="false">
      <el-button slot="trigger" size="small" type="primary">选取文件</el-button>
      <el-button plain style="margin-left: 10px;" size="small" type="success" @click="submitUpload">上传到服务器</el-button>
      <div slot="tip" class="el-upload__tip">只能上传jpg/png文件，一次不能超过9张</div>
    </el-upload>
      </div>
    
</div>
  
</template>

<script>
import {Toast} from 'mint-ui'
import fileApi from '@/api/file'
import {Upload,Button} from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
export default {
    data() {
      return {
        fileList: [],
      }
    },
    components: {
       "el-upload": Upload,
       "el-button": Button
    },
    methods: {
      submitUpload() {
        this.$refs.upload.submit();
      }, 
      uploadSuccess(uploadFile){
         if (uploadFile.code === 0) {
            Toast(uploadFile.message) 
        } else {
            Toast(uploadFile.message)
        }
      },
      beforeUpload(file){
            let formData = new FormData();
            let config = {
              headers: {'Content-Type': 'multipart/form-data'}
            }
            formData.append('file', file);
            fileApi.uploadFile(formData,config).then(res => {
                    if (res.data.code === 0) {
                        Toast(res.data.message)
                    } else {
                      Toast(res.data.message)
                    }
            })
            return false;
      }
    }
  }
</script>

<style lang="scss" scoped>
li.el-upload-list__item.is-ready {
          width: 50px;
          
  }
.upload-a{
  background-color: #0000;
  width: 400px;
  margin: auto;
  text-align: center;
  // float: left;el-upload-list__item is-ready
  
}
.texta{
  font-family: "Helvetica Neue";
  text-align: center;
  background-color: whitesmoke;
}
</style>

