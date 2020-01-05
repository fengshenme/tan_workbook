import request from '@/utils/request'

const grouname = 'api'

//获取新闻详情
export function getNewIn (id) {
  return request({
    url: `/${grouname}/getnew/${id}`,
    method: 'get'
  })
}
// 获取评论
export function getcomments (id, page) {
  return request({
    url: `/${grouname}/getcomments/${id}/${page}`,
    method: 'get'
  })
}
// 添加评论
export function postcomment (id, pojo) {
  return request({
    url: `/${grouname}/postcomment/${id}`,
    method: 'post',
    data: pojo
  })
}

export default {
  getlunbotuList () {
    return request({
      url: `/${grouname}/getlunbo`,
      method: 'get'
    })
  },
  // 图片获取
  getthumimages (id) {
    return request({
      url: `/${grouname}/getthumimages/${id}`,
      method: 'get'
    })
  },
  getnewslist (page) {
    return request({
      url: `/${grouname}/getnewslist/${page}`,
      method: 'get'
    })
  },
  // 获取所有的图片分类
  getimgcategory () {
    return request({
      url: `/${grouname}/getimgcategory`,
      method: 'get'
    })
  },
  // 根据分类id,获取图片列表
  getimages (id) {
    return request({
      url: `/${grouname}/getimages/${id}`,
      method: 'get'
    })
  },
  // 图片详情获取
  getimageInfo (id) {
    return request({
      url: `/${grouname}/getimageInfo/${id}`,
      method: 'get'
    })
  },
  // 获取购物车商品列表
  getshopcarlist (id) {
    return request({
      url: `/${grouname}/goods/getshopcarlist/${id}`,
      method: 'get'
    })
  },
  // 获取商品的图文介绍
  getgoodsdesc (id) {
    return request({
      url: `/${grouname}/goods/getdesc/${id}`,
      method: 'get'
    })
  },
  // 获取商品列表
  getgoodslist (page) {
    return request({
      url: `/${grouname}/getgoods/${page}`,
      method: 'get'
    })
  },
  // 获取商品详情
  getgoodsinfo (id) {
    return request({
      url: `/${grouname}/goods/getinfo/${id}`,
      method: 'get'
    })
  }
}
