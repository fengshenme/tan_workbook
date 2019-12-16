<template>
  <div>
    <quillEditor ref="myTextEditor"
                      v-model="content"
                      :options="editorOption"
                      >

                      </quillEditor>
      <button @click="save()">发布</button>
  </div>
</template>

<script>
import 'quill/dist/quill.core.css'
import 'quill/dist/quill.snow.css'
import 'quill/dist/quill.bubble.css'
import '@/assets/js/ssr.js' 
import { quillEditor } from '@/assets/js/vue-quill-editor.js'
import hljs from 'highlight.js' 
// import fileApi from "@/api/file.js"
export default {
  components: {
    quillEditor
  },
  data() {
      return {
        name: 'editer',
        content: '输入',
        editorOption: {
          modules: {
            toolbar: [
              ['bold', 'italic', 'underline', 'strike'],
              ['blockquote', 'code-block'],
              [{ 'header': 1 }, { 'header': 2 }],
              [{ 'list': 'ordered' }, { 'list': 'bullet' }],
              [{ 'script': 'sub' }, { 'script': 'super' }],
              [{ 'direction': 'rtl' }],
              [{ 'size': ['small', false, 'large', 'huge'] }],
              [{ 'header': [1, 2, 3, 4, 5, 6, false] }],
              [{ 'font': [] }],
              [{ 'color': [] }, { 'background': [] }],
              [{ 'align': [] }],
              ['link', 'image', 'video']
            ],
            syntax: {
              highlight: text => hljs.highlightAuto(text).value
            }
          }
        }
      }
    },
    methods: {
      save(){
        console.log(this.content)
        // fileApi.editorSave(this.content).then(res=>{

        // })
      }
    },
    computed: {
      editor() {
        return this.$refs.myTextEditor.quill
      },
      contentCode() {
        return hljs.highlightAuto(this.content).value
      }
    }
    
}
</script>
<style lang="scss" scoped>
  
</style>
