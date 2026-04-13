// #version and #defines injected by preamble

out vec4 FragColor;

in vec3 vWorldPos;
in vec3 vNormal;
in vec2 vTexCoord;

#ifdef HAS_TEXTURE
uniform sampler2D uDiffuseTex;
#endif

#ifdef HAS_NORMAL_MAP
uniform sampler2D uNormalTex;
#endif

#ifdef HAS_LIGHTING
uniform vec3 uLightDir;
uniform vec3 uLightColor;
uniform vec3 uAmbient;
#endif

void main(){
    vec3 baseColor = vec3(1.0);

#ifdef HAS_TEXTURE
    baseColor = texture(uDiffuseTex, vTexCoord).rgb;
#endif

    vec3 normal = normalize(vNormal);

#ifdef HAS_NORMAL_MAP
    vec3 mapN = texture(uNormalTex, vTexCoord).rgb * 2.0 - 1.0;
    normal = normalize(mapN);
#endif

#ifdef HAS_LIGHTING
    float diff = max(dot(normal, normalize(-uLightDir)), 0.0);
    vec3 lit = uAmbient + uLightColor * diff;
    baseColor *= lit;
#endif

    FragColor = vec4(baseColor, 1.0);
}
