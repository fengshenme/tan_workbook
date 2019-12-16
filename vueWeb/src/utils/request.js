import axios from 'axios'
import {getUser} from '@/utils/auth'
import {httpUrl} from '@/utils/common'
// 创建axios实例
const service = axios.create({
  baseURL: httpUrl, // api的base_url
  timeout: 300000, // 请求超时时间,
  headers: { 'Authorization': 'Bearer ' + getUser().token }
})
export default service
