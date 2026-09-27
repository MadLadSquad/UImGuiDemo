export default 
{
  // Serves your static assets for incoming web traffic
  async fetch(request: Request, env: any): Promise<Response> 
  {
    return env.ASSETS.fetch(request);
  },

  // Runs on your Cron schedule
  async scheduled(controller: ScheduledController, env: any, ctx: ExecutionContext): Promise<void> 
  {
    const deployHookUrl = "https://api.cloudflare.com/client/v4/workers/builds/deploy_hooks/9fc3d09d-e874-4a91-a59d-0fe81fd29c32";

    const res = await fetch(
      deployHookUrl, 
      {
        method: "POST"
      }
    );

    if (!res.ok) 
    {
      console.error(`Rebuild trigger failed with status: ${res.status}`);
    }
  }
};

