import request from '@/utils/request'


const grouname = 'file'

/**首页轮播图 */
export function indexImg(filetype) {
    return request({
      url: `/img/indeximg/${filetype}`,
      method: 'get',
    })
}
/**商城文件 */
export function uploadFile (pojo) {
    return request({
      url: `/${grouname}/uploadFile`,
      method: 'post',
      data: pojo
    })
  }

/**根据类别查找 */
export function  fileShowList (filetype) {
    return request({
      url: `/${grouname}/fileList/${filetype}`,
      method: 'get'
    })
  }

/** 图片显示 */
export function  fileShow (code) {
    return request({
      url: `/img/file/${code}`,
      method: 'get'
    })
  }
/** 视频播放 */ 
export function fileVideoShow (code) {
    return request({
      url: `/${grouname}/fileVideo/${code}`,
      method: 'get'
    })
  }
/** 根据文件id删除文件 */
export function DelFile (id) {
    return request({
      url: `/${grouname}/delFile/${id}`,
      method: 'delete'
    })
  }
/**  根据类别查找并分页*/
export function FetchList ( filetype,page,pagesize) {
    return request({
      url: `/${grouname}/filePageList/${filetype}/${page}/${pagesize}`,
      method: 'get',
    })
  }
/** 保存编辑器内容 */
export function  editorSave(){
    return request({
      url: `/${grouname}/editorsave/`,
      method: 'post'
    })
  }
