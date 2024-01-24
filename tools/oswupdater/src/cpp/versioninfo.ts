import fs from 'fs';
import { ClientManifest } from '../manifest';
export class VersionInfo {
    static CreateVersionFileFromManifest(path: string, manifest: ClientManifest): void {
        var fullText = "";
        fullText += "// DO NOT EDIT; AUTOGENERATED FILE BY OSWUPDATER\n"
        fullText += "#pragma once\n";
        fullText += `#define STEAM_MANIFEST_VERSION "${manifest.version}"\n`
        fullText += `#define STEAM_MANIFEST_VERSION_NUM ${manifest.version}\n`
        fullText += `#define STEAM_BINS_UBUNTU12_NAME "${manifest.zips["bins_ubuntu12"].file}"\n`
        fullText += `#define STEAM_BINS_SDK_UBUNTU12_NAME "${manifest.zips["bins_sdk_ubuntu12"].file}"\n`
        fullText += `#define STEAM_BINS_MISC_UBUNTU12_NAME "${manifest.zips["bins_misc_ubuntu12"].file}"`
        fs.writeFileSync(path, fullText);
    }
}