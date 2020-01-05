import Cookies from 'js-cookie'

// 定义只读常量
const TokenKey = 'UserToken'
const NameKey = 'UserName'
const MobileKey = 'UserMobile'

export function getUrlParam (name) {
  var reg = new RegExp('(^|&)' + name + '=([^&]*)(&|$)')
  var r = window.location.search.substr(1).match(reg)
  if (r != null) return unescape(r[2])
  return null
}


// 设置用户
export function setUser ( nickname,token,mobile) {
  Cookies.set(TokenKey, token)
  Cookies.set(NameKey, nickname)
  Cookies.set(MobileKey, mobile)
}
// 获取用户数据
export function getUser () {
  return {
    token: Cookies.get(TokenKey),
    name: Cookies.get(NameKey),
    mobile:Cookies.get(MobileKey),
  }
}

// 移除用户数据
export function removeUser () {
  Cookies.remove(TokenKey)
  Cookies.remove(NameKey)
  Cookies.remove(MobileKey)
}
