<template>
    <div>
        <router-view  />
    </div>
</template>

<script>
import { getUser } from '@/utils/auth'
export default {
    created() {
        this.user= getUser();
    },
}
</script>

<style lang="scss" scoped>

</style>