import Vue from 'vue'
import VueRouter from 'vue-router'

Vue.use(VueRouter)

const routes = [
      {path:'/' , redirect:'/home/index',},
      // 配置路由规则的
      {path:'/home' , redirect:'/home/index', name:'HomeContainer', component: () => import('@/components/tabbar/HomeContainer.vue') , // 当路由为空时，会重定向到/home
        children: [
          { path: 'index' , component: () => import('@/components/home/index.vue')},
          { path: 'newslist', component: () => import('@/components/home/news/NewsList.vue') },
          { path: 'newsinfo/:id', component: () =>import('@/components/home/news/NewsInfo.vue') },
          { path: 'photolist', component: () => import('@/components/home/photos/PhotoList.vue') },
          { path: 'photoinfo/:id', component: () => import('@/components/home/photos/PhotoInfo.vue') },
          { path: 'goodslist', component: () => import('@/components/home/goods/GoodsList.vue') },
          { path: 'goodsinfo/:id', name: 'goodsinfo', component: () => import('@/components/home/goods/GoodsInfo.vue') },
          { path: 'goodsdesc/:id', name: 'goodsdesc', component: () => import('@/components/home/goods/GoodsDesc.vue') },
          { path: 'goodscomment/:id', name: 'goodscomment', component: () => import('@/components/home/goods/GoodsComment.vue') },
        ]
      },
      { path: '/search', name: 'SearchContainer', component: () => import('@/components/tabbar/SearchContainer.vue') },
      { path: '/shopcar',name: 'ShopcarContainer', component: () => import('@/components/tabbar/ShopcarContainer.vue') },
    { 
      path: '/user', redirect: '/user/userinfo',name: 'MemberContainer', component: () => import('@/components/tabbar/MemberContainer.vue') ,
      children: [
        { path: 'login', component: () => import('@/components/user/login.vue') },
        { path: 'register', name: 'Register', component: () => import('@/components/user/register.vue') },
        { path: 'userinfo', name: 'userInfo', component: () => import('@/components/user/userinfo.vue') },
        { path: 'editer', name:'Editer', component: () => import('../components/subcomponents/editer.vue')},
        { path: "file", name: "File", component: ()=> import('../components/file/file.vue')},
        { path: "fileadmin", name: "FileAdmin", component: ()=> import('../components/file/fileadmin.vue')},
        { path: "message", name: "Message", component: () => import('@/components/user/message.vue')}
      ]
    },
    ]
  
const router = new VueRouter({
  routes,
  linkActiveClass: 'mui-active'// 覆盖默认的路由高亮的类,默认的类的叫做router-link-active
})

export default router
