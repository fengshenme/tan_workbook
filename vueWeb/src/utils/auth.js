import Cookies from 'js-cookie'

const TokenKey = 'User-Token'
const NameKey = 'User-Name'
const MobileKey = 'User-Mobile'

export function setUser (token, nickname,mobile) {
  Cookies.set(NameKey, nickname)
  Cookies.set(TokenKey, token)
  Cookies.set(MobileKey, mobile)
}

export function getUser () {
  return {
    token: Cookies.get(TokenKey),
    name: Cookies.get(NameKey),
    mobile:Cookies.get(MobileKey),
  }
}

export function removeUser () {
  Cookies.remove(TokenKey)
  Cookies.remove(NameKey)
  Cookies.remove(MobileKey)
}
