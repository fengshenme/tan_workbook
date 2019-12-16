import request from '@/utils/request'

const grouname = 'api'

export default {
  uploadFile (pojo) {
    return request({
      url: `/${grouname}/uploadFile`,
      method: 'post',
      data: pojo
    })
  },
  // 根据类别查找
  fileShowList (filetype) {
    return request({
      url: `/${grouname}/fileList/${filetype}`,
      method: 'get'
    })
  },
  // 图片显示
  fileShow (code) {
    return request({
      url: `/img/file/${code}`,
      method: 'get'
    })
  },
  // 视频播放
  fileVideoShow (code) {
    return request({
      url: `/${grouname}/fileVideo/${code}`,
      method: 'get'
    })
  },
  // 根据文件id删除文件
  delFile (id) {
    return request({
      url: `/${grouname}/delFile/${id}`,
      method: 'delete'
    })
  },
  // 根据类别查找并分页
  fetchList (query, filetype) {
    return request({
      url: `/${grouname}/filePageList/${filetype}`,
      method: 'get',
      params: query
    })
  },
  //保存编辑器内容
  editorSave(){
    return request({
      url: `/${grouname}/editorsave/`,
      method: 'post'
    })
  }
}
